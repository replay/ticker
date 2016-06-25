#ifndef TICKER_H_
#define TICKER_H_

#include <sstream>
#include <stdio.h>
#include <dlfcn.h>
#include <iostream>
#include <vector>
#include <string>
#include <data_provider.h>

#define FILENAME_MAX_LENGTH 256

using namespace std;


class Ticker
{
	protected:
		vector<DataProvider*> _data_providers;
		int _load_data_provider(string);

	public:
		void run(vector<string>);
};

#endif // TICKER_H_
