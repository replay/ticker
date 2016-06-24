#ifndef DATA_PROVIDER_H_
#define DATA_PROVIDER_H_

#include <string>

using namespace std;


class DataProvider
{
	public:
		virtual string get_name() = 0;
};

#endif // DATA_PROVIDER_H_