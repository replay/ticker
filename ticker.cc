#include <boost/format.hpp>
#include <data_provider.h>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <ticker.h>


int Ticker::_load_data_provider(string provider_name)
{
	char* filename;
	void* library;
	void* func;
	void* provider_vp;
	void* (*loader)();
	void* loader_vp;
	DataProvider *provider;

	filename = (char *) malloc(FILENAME_MAX_LENGTH);
	snprintf(filename, FILENAME_MAX_LENGTH, "./%s_provider.so",
		 provider_name.c_str());
	cout << filename << "\n";
	library = dlopen(filename, RTLD_LAZY);
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
}
