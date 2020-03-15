#include "WindowsMessageMap.h"
#include <Windows.h>
#include <string>
#include <sstream>
#include <iomanip>

// top secret messages
#define WM_UAHDESTROYWINDOW 0x0090
#define WM_UAHDRAWMENU 0x0091
#define WM_UAHDRAWMENUITEM 0x0092
#define WM_UAHINITMENU 0x0093
#define WM_UAHMEASUREMENUITEM 0x0094
#define WM_UAHNCPAINTMENUPOPUP 0x0095

#define REGISTER_MESSAGE(msg){msg,#msg}

WindowsMessageMap::WindowsMessageMap()
	:
	map({})
{}

std::string WindowsMessageMap::operator()(DWORD msg, LPARAM lp, WPARAM wp) const
{
	return NULL;
}