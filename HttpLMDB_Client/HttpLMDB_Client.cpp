// HttpLMDB_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	std::wstring dbname = _T("cache_v100");
	if (Init(dbname) == false)
	{
		std::wcout << _T("Init failed") << std::endl;
		return 0;
	}

	::Sleep(1000);

	std::wstring key = _T("key_v10");
	std::wstring value = _T("value_v10");
	SetData(key, value);

	value = _T("");

	GetData(key, value);

	std::wcout << _T("key:") << key << _T(" value:") << value << std::endl;

	Uninit(dbname);
    return 0;
}

