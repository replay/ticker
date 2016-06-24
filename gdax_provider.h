#ifndef GDAX_PROVIDER_H_
#define GDAX_PROVIDER_H_

#include <data_provider.h>
#include <string>

using namespace std;


class GdaxProvider: public DataProvider {
	public:
		string get_name();
};

extern "C"
{
    void* load_data_provider(void)
    {
        return reinterpret_cast<void*>(new GdaxProvider);
    }

    void delete_data_provider(void* obj)
    {
        delete reinterpret_cast<GdaxProvider*>(obj);
    }
}

#endif // GDAX_PROVIDER_H_
