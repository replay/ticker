#include <boost/format.hpp>
#include <data_provider.h>
#include <ticker.h>


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
		fprintf (stderr, "%s\n", dlerror());
		exit(1);
	}
	dlerror();
	loader_vp = dlsym(library, "load_data_provider");
	if (!loader_vp) {
		fprintf (stderr, "function not found in object");
		exit(1);
	}
	loader = reinterpret_cast<void*(*)()>(loader_vp);
	provider = reinterpret_cast<DataProvider*>(loader());
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
