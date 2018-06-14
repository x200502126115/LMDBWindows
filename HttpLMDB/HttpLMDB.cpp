// HttpLMDB.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "HttpLMDB.h"

#include "..\Include\messagetypes.h"
#include "..\Include\Helper.h"
#include "..\Include\Constants.h"

// This is an example of an exported variable
HTTPLMDB_API int nHttpLMDB=0;

// This is an example of an exported function.
HTTPLMDB_API int fnHttpLMDB(void)
{
    return 42;
}

// This is the constructor of a class that has been exported.
// see HttpLMDB.h for the class definition
CHttpLMDB::CHttpLMDB()
{
    return;
}

GetNodeData _data;

bool HTTPLMDB_API Init(std::wstring dbname)
{
	std::wstring ip = CHelper::GetIP();
	std::wstring port = Constants::MasterNodePort;

	std::wstring url = CHelper::BuildURL(ip, port);
	std::wcout << L"Client " << url << std::endl;

	http_client client(url);

	std::wostringstream buf;
	buf << Constants::Request << Constants::VerbGetNode
		<< _T("&dbname=") << dbname;

	http_response response;

	try
	{
		response = client.request(methods::GET, buf.str()).get();
		wcout << response.to_string() << endl;
	}
	catch (http_exception ex)
	{
		std::string err = ex.what();
	}	

	json::value jdata = json::value::array();
	jdata = response.extract_json().get();

	if (jdata.is_null())
	{
		std::wcout << _T("no JSON data...") << std::endl;
		return false;
	}

	_data = GetNodeData::FromJSON(jdata.as_object());						

	TCHAR sz[255];
	_stprintf_s(sz, _T("GetNodeData ip:%s port:%s name:%s dbname:%s\n"), _data.ip.c_str(), _data.port.c_str(), _data.name.c_str(), _data.dbName.c_str());
	_tprintf(sz);

	return true;
}

bool HTTPLMDB_API Uninit(std::wstring dbname)
{
	std::wstring ip = CHelper::GetIP();
	std::wstring port = Constants::MasterNodePort;

	std::wstring url = CHelper::BuildURL(ip, port);
	std::wcout << L"Client " << url << std::endl;

	http_client client(url);

	std::wostringstream buf;
	buf << Constants::Request << Constants::VerbReleaseNode
		<< _T("&dbname=") << dbname;

	http_response response;

	try
	{
		response = client.request(methods::GET, buf.str()).get();
		wcout << response.to_string() << endl;
	}
	catch (http_exception ex)
	{
		std::string err = ex.what();
	}

	json::value jdata = json::value::array();
	jdata = response.extract_json().get();

	if (jdata.is_null())
	{
		std::wcout << _T("no JSON data...") << std::endl;
		return false;
	}

	_data = GetNodeData::FromJSON(jdata.as_object());

	TCHAR sz[255];
	_stprintf_s(sz, _T("GetNodeData ip:%s port:%s name:%s dbname:%s\n"), _data.ip.c_str(), _data.port.c_str(), _data.name.c_str(), _data.dbName.c_str());
	_tprintf(sz);

	return true;
}

bool HTTPLMDB_API SetData(std::wstring key, std::wstring valueb64, DWORD dwLen)
{
	return true;
}

bool HTTPLMDB_API SetData(std::wstring key, std::wstring value)
{
	std::wstring url = CHelper::BuildURL(_data.ip, _data.port);
	http_client client_lmdb(url);

	std::wostringstream buf;
	buf << Constants::Request << Constants::VerbSetData
		<< _T("&key=") << key
		<< _T("&value=") << value;

	http_response response;
	response = client_lmdb.request(methods::GET, buf.str()).get();

	wcout << response.to_string() << endl;

	return true;
}

bool HTTPLMDB_API GetData(std::wstring key, std::wstring & value)
{
	std::wstring url = CHelper::BuildURL(_data.ip, _data.port);
	http_client client_lmdb(url);

	std::wostringstream buf;
	buf << Constants::Request << Constants::VerbGetData
		<< _T("&key=") << key;

	wcout << buf.str() << endl;

	http_response response;
	response = client_lmdb.request(methods::GET, buf.str()).get();

	wcout << response.to_string() << endl;

	json::value jdata = json::value::array();
	jdata = response.extract_json().get();
	Data data = Data::FromJSON(jdata.as_object());

	TCHAR sz[255];
	_stprintf_s(sz, _T("Data key:%s value:%s\n"), data.key.c_str(), data.value.c_str());
	_tprintf(sz);

	value = data.value;

	return true;
}
