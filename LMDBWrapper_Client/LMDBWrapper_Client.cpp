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

	count = 200;

	if (argc == 2)
	{
		count = atoi(argv[1]);
	}


	values = (int *)malloc(count * sizeof(int));

	for (i = 0; i<count; i++) {
		values[i] = rand() % 1024;
	}

	char szDbName[255];
	strcpy_s(szDbName, "cache_v1000");

	CLMDBWrapper wrapper;
	wrapper.Init(szDbName);

	printf("Adding %d values\n", count);
	DWORD dwStart = GetTickCount();
	for (i = 0; i<count; i++)
	{
		char szKey[255];
		char szValue[255];
		sprintf(szKey, "key_%d", i);
		sprintf(szValue, "value_%d", i);

		//printf("SET key:%s value:%s\n", szKey, szValue);

		wrapper.SetData(szKey, szValue);
	}

	DWORD dwStop = GetTickCount();
	sprintf(szDebug, "Elapsed for put: %ld ms\n", dwStop - dwStart);
	printf(szDebug);

	dwStart = GetTickCount();
	for (int i = 0; i < count; i++)
	{
		char szKey[255];
		char szValue[255];
		sprintf(szKey, "key_%d", i);
		memset(szValue, 0, 255);

		if (i > 101)
		{
			int i2 = 101;
		}

		wrapper.GetData(szKey, szValue);

		//printf("GET key:%s value:%s\n", szKey, szValue);
	}
	dwStop = GetTickCount();
	sprintf(szDebug, "Elapsed for get: %ld ms\n", dwStop - dwStart);
	printf(szDebug);

	wrapper.Uninit(szDbName);
	return 0;
}

