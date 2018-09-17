
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include "SLABCP2110.h"

#pragma comment(lib, "SLABHIDToUART.lib");


using namespace std;

int main()
{
	HMODULE Implicit_Load = LoadLibrary(L"SLABHIDtoUART.dll");
	unsigned int major = 0, minor = 0;
	BOOL release = 0;
	if (Implicit_Load != NULL)
	{
		HidUart_GetLibraryVersion(reinterpret_cast<BYTE*>(&major), reinterpret_cast<BYTE*>(&minor), &release);
		cout << "major :" << major << endl
			<< "minor :" << minor << endl
			<< "release :" << release << endl;
		cout << "Success!"<< endl;

	}
	else
		cout << "Fail" << endl;
}
