
#include "pch.h"
#include <iostream>
#include <Windows.h>
//include .h file
//#include "SLABCP2110.h"
using namespace std;

//define a new function pointer to operate the function in dll
typedef int (WINAPI* HIDUart_GetVersionFp)(BYTE *major, BYTE* minor , BOOL *release);
int main()
{
	//declare a new HINSTANCE to load dll
	HMODULE HIDUART_DLL = LoadLibrary(L"SLABHIDtoUART.dll");
	uint32_t major = 0, minor = 0;
	BOOL release = 0;
	if (HIDUART_DLL != NULL)
	{
		cout << "Success!" << endl;
		//declare new function pointer to the function in dll
		HIDUart_GetVersionFp CPGetVersion = (HIDUart_GetVersionFp)GetProcAddress(HIDUART_DLL, "HidUart_GetLibraryVersion");
		CPGetVersion(reinterpret_cast<BYTE*>(&major), reinterpret_cast<BYTE*>(&minor), &release);
		cout << "Major :" << major << endl
			<< "minor :" << minor << endl
			<< "release :" << release << endl;

	}
	else
		cout << "Fail to load dll" << endl;
	FreeLibrary(HIDUART_DLL);
}

