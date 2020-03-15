#include "Window.h"

// Entry point
int CALLBACK WinMain(
	_In_ HINSTANCE     hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR		   lpCmdLine,
	_In_ int	       nCmdShow )
{
	Window wnd(800, 300, "Linux rules, Windows drools");

	// message pump
	MSG msg;
	BOOL gResult; // not C++ bool, it's an int
	while ((gResult = GetMessage(&msg, nullptr, 0, 0)) > 0) // see if captured value is > 0
	{
		TranslateMessage(&msg); // constant pointer
		DispatchMessage(&msg);
	}

	if (gResult == -1)
		return -1;
	else
		return msg.wParam; // the post quit message WM_QUIT
}