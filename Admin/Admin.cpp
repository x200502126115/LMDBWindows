// Admin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "..\Include\ServerHelper.h"
#include "..\Include\Constants.h"

int wmain(int argc, wchar_t *argv[])
{
	std::wstring defaultAddress = _T("localhost");
	std::wstring port = Constants::MasterNodePort;

	if (argc == 2)
	{
		port = argv[1];
	}
	if (argc == 3)
	{
		defaultAddress = argv[1];
		port = argv[2];
	}

	if (argc == 4)
	{
		defaultAddress = argv[1];
		port = argv[2];
	}

	std::wstring url = ServerHelper::BuildURL(defaultAddress, port);
	std::wcout << L"Client " << url << std::endl;

	std::wstring cmd;

	std::wcout << _T("Enter a command:");
	std::wcin >> cmd;

	http_client client(url);

	http_response response;

	try
	{
		response = client.request(methods::GET, cmd).get();
		wcout << response.to_string() << endl;
	}
	catch (http_exception ex)
	{
		std::string err = ex.what();
	}

	return 0;
}

