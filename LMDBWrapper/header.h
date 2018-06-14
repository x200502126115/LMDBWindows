// header.h : include file for standard system include files,
// or project specific include files
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit
#define _AFX_NO_MFC_CONTROLS_IN_DIALOGS         // remove support for MFC controls in dialogs

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include <map>
#include <vector>
#include <string>
#include <exception>
#include <iostream>
#include <streambuf>
#include <sstream>
#include <fstream>

// Windows Header Files:
#include <tchar.h>
#include <windows.h>

#include "..\Include\LMDBWindowsDll.h" 
#include "..\Include\lmdb-dll.h"
#include "..\Include\midl-dll.h"

// TODO: reference additional headers your program requires here
#ifdef _WIN64
#ifdef _DEBUG
#pragma comment (lib, "..\\Lib\\LMDBWindowsDllD64.lib")
#pragma comment (lib, "..\\Lib\\MySharedStuff.lib")
#else
#pragma comment (lib, "..\\Lib\\LMDBWindowsDll64.lib")
#endif
#else
#ifdef _DEBUG
#pragma comment (lib, "..\\Lib\\LMDBWindowsDllD.lib")
#else
#pragma comment (lib, "..\\Lib\\LMDBWindowsDll.lib")
#endif
#endif
