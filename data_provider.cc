#include <data_provider.h>


DataProvider::DataProvider(void (*del)(void*))
	: _delete(del)
{
}

DataProvider::~DataProvider()
{
}

void DataProvider::del()
{
	(*_delete)(reinterpret_cast<void*>(this));
}

