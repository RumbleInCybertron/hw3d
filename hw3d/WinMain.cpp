#include <Windows.h>

// returns a 32-bit integer value
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE:
		PostQuitMessage(69); // return value that you would like
		break;                    // the application to exit with (return code)
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int CALLBACK WinMain(
	_In_ HINSTANCE     hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR		   lpCmdLine,
	_In_ int	       nCmdShow )
{
	const auto pClassName = "hw3dbooty";
	// register window class
	WNDCLASSEX wc = { 0 };
	wc.cbSize = sizeof(wc);
	wc.style = CS_OWNDC;
	wc.lpfnWndProc = WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = nullptr;
	wc.hbrBackground = nullptr;
	wc.lpszMenuName = nullptr;
	wc.lpszClassName = pClassName;
	wc.hIconSm = nullptr;
	RegisterClassEx( &wc);
	// create window instance
	HWND hWnd = CreateWindowEx(
		0, pClassName,
		"Happy Hard Window",
		WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
		200, 200, 640 , 480,
		nullptr, nullptr, hInstance, nullptr
	);
	// show the damn window
	ShowWindow(hWnd, SW_SHOW);

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