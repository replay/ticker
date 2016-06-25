#ifndef DATA_PROVIDER_H_
#define DATA_PROVIDER_H_

#include <string>

using namespace std;


class DataProvider
{
	public:
		virtual string get_symbol() = 0;
		virtual string get_name() = 0;
		virtual int get_rate(string, string) = 0;
};

#endif // DATA_PROVIDER_H_
