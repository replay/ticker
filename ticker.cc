#include <boost/format.hpp>
#include <data_provider.h>
#include <ticker.h>


Ticker::~Ticker()
{
	for (auto i = this->_data_providers.begin(); i != this->_data_providers.end(); ++i)
		delete *i;
}

int Ticker::_load_data_provider(string provider_name)
{
	void* library;
	void* (*loader)();
	void* loader_vp;
	stringstream filename;
	DataProvider *provider;

	filename << "./" << provider_name << "_provider.so";
	library = dlopen(filename.str().c_str(), RTLD_LAZY);
	if (!library) {
		cerr << dlerror() << endl;
		exit(1);
	}
	dlerror();
	loader_vp = dlsym(library, "load_data_provider");
	if (!loader_vp) {
		cerr << "symbol not found in object" << endl;
		exit(1);
	}
	loader = reinterpret_cast<void*(*)()>(loader_vp);
	provider = (DataProvider*) loader();
	this->_data_providers.push_back(provider);

	cout << this->_data_providers.at(0)->get_name() << "\n";

	return 0;
}

void Ticker::run(vector<string> data_providers)
{
	for (auto i = data_providers.begin(); i != data_providers.end(); ++i)
		this->_load_data_provider(*i);

	DataProvider *dp = this->_data_providers.at(0);
	dp->get_rate("USD", "ETH");
}
