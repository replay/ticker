#ifndef GDAX_PROVIDER_H_
#define GDAX_PROVIDER_H_

#include <string>
#include <iostream>

#include <curl/curl.h>
#include <boost/format.hpp>

#include <data_provider.h>

using namespace std;

#define API_URL "https://api.gdax.com/products/%1%-%2%/ticker"


class GdaxProvider: public DataProvider {
	public:
		GdaxProvider(void (*del)(void*));
		~GdaxProvider();
		string get_symbol();
		string get_name();
		int get_rate(string, string);
};

#endif // GDAX_PROVIDER_H_
