// cl g1.cpp kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib

#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	// Get window handle to console, and device context
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//Here's a 5 pixels wide RED line [from initial 0,0] to 300,300
	HPEN pen =CreatePen(PS_SOLID,15,RGB(0,255,0));
	SelectObject(device_context,pen);

	MoveToEx(device_context,300, 300, NULL);
	LineTo(device_context,567, 245);
	LineTo(device_context,123, 876);
	LineTo(device_context,300, 300);

	Rectangle(device_context, 200, 200, 226, 144);

	Ellipse(device_context, 600, 600, 420, 800);

	COLORREF clrRed  = RGB(255, 25, 5);
	COLORREF clrAqua = RGB(0, 255, 255);
	COLORREF clrNavy = RGB(0, 0, 128);

	SetBkColor(device_context, RGB(255, 255, 255));
	SetTextColor(device_context, clrRed);
	TextOut(device_context, 50, 42, "Moula Jatt", 13);
	SetBkColor(device_context, clrNavy);
	SetTextColor(device_context, clrAqua);
	TextOut(device_context, 50, 80, "The all time great film", 27);	 

	ReleaseDC(console_handle, device_context);
	cin.ignore();
	return 0;
}