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
