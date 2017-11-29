/////////////////////////////////////////////////////////////////////////////////////////////
// WinMain.cpp
//
// Win32 API entry pointe
/////////////////////////////////////////////////////////////////////////////////////////////

#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#include "AppWindow.h"
#include "Base/Common/Application.h"

extern CApplication *CreateApplication(const char *cmdline);


#define WINMAIN WinMain

/////////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WINMAIN(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nShowCmd)
{
    printf("WinMain Hello World!\n");
    
	const char *strcmd = lpCmdLine;
    CAppWindow *appwnd = new CAppWindow(hInstance);
    CApplication *app = CreateApplication(strcmd);
    app->Run(appwnd);

    
    delete (appwnd);
    delete (app);
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
