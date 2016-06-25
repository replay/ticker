#include <gdax_provider.h>

GdaxProvider::GdaxProvider(void (*del)(void*))
	: DataProvider(del)
{
}

GdaxProvider::~GdaxProvider()
{
}

string GdaxProvider::get_name()
{
	string name = "gdax_provider";
	return name;
}

string GdaxProvider::get_symbol()
{
	string symbol = "GDX";
	return symbol;
}

int GdaxProvider::get_rate(string src, string dst)
{
	string product_url;
	//CURLcode res;
	CURL *curl = curl_easy_init();
	if(!curl) {
		return -1;
	}

	product_url = str( boost::format(API_URL) % src % dst ) ;

	curl_easy_setopt(curl, CURLOPT_URL, product_url);
	//curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	cout << "ran" << endl;

	return 0;
}

extern "C"
{
    void delete_data_provider(void* obj)
    {
        delete reinterpret_cast<GdaxProvider*>(obj);
    }

    void* load_data_provider(void)
    {
        return new GdaxProvider(delete_data_provider);
    }
}
