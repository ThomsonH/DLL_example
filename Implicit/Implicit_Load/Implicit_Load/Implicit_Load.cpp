
#include "pch.h"
#include <iostream>
#include <Windows.h>
#include "SLABCP2110.h"

#pragma comment(lib, "SLABHIDToUART.lib")

using namespace std;

int main()
{
	unsigned int major = 0, minor = 0;
	BOOL release = 0;

	HidUart_GetLibraryVersion(reinterpret_cast<BYTE*>(&major), reinterpret_cast<BYTE*>(&minor), &release);
	cout << "major :" << major << endl
		<< "minor :" << minor << endl
		<< "release :" << release << endl;
}
