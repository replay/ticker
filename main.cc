#include <iostream>
#include <string>
#include <curl/curl.h>

#include <main.h>
#include <ticker.h>
#include <option_parser.h>


int main(int argc, char** argv)
{
	vector<string> data_providers;
	Ticker ticker;

	OptionParser parser(argc, argv);

	data_providers =  parser.data_providers();
	if (data_providers.size() == 0)
		return 0;

	ticker.run(data_providers);
}

