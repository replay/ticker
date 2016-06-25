#ifndef GDAX_PROVIDER_H_
#define GDAX_PROVIDER_H_

#include <string>

#include <curl/curl.h>
#include <boost/format.hpp>

#include <data_provider.h>

using namespace std;

#define API_URL "https://api.gdax.com/products/%1%-%2%/ticker"


class GdaxProvider: public DataProvider {
	public:
		string get_symbol();
		string get_name();
		int get_rate(string, string);
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
