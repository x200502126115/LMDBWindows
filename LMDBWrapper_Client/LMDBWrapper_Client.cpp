// LMDBWrapper_Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Include\CWrapper.h"

int main(int argc, char * argv[])
{
	int i = 0, j = 0, rc;
	int count;
	int *values;
	char szDebug[255];

	count = 2;

	if (argc == 2)
	{
		count = atoi(argv[1]);
	}


	values = (int *)malloc(count * sizeof(int));

	for (i = 0; i<count; i++) {
		values[i] = rand() % 1024;
	}

	std::wstring dbName = _T("cache_v1000");
	CLMDBWrapper wrapper;
	wrapper.Init(dbName);

	printf("Adding %d values\n", count);
	DWORD dwStart = GetTickCount();
	for (i = 0; i<count; i++)
	{
		TCHAR szKey[255];
		TCHAR szValue[255];
		_stprintf_s(szKey, _T("key_%d"), i);
		_stprintf_s(szValue, _T("value_%d"), i);

		wrapper.SetData(szKey, szValue);
	}
	DWORD dwStop = GetTickCount();
	sprintf_s(szDebug, ("Elapsed for put: %ld ms\n"), dwStop - dwStart);
	printf(szDebug);

	dwStart = GetTickCount();
	for (int i = 0; i < count; i++)
	{
		TCHAR szKey[255];
		TCHAR szValue[255];
		_stprintf_s(szKey, _T("key_%d"), i);
		_stprintf_s(szValue, _T("value_%d"), i);

		wrapper.GetData(szKey, szValue);

		//std::wcout << value << std::endl;
	}
	dwStop = GetTickCount();
	sprintf_s(szDebug, ("Elapsed for get: %ld ms\n"), dwStop - dwStart);
	printf(szDebug);

	wrapper.Uninit(dbName);
	return 0;
}

