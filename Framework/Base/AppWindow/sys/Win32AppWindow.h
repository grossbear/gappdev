/////////////////////////////////////////////////////////////////////////////////////////////
// Win32AppWindow.h
//
// Win32 API Application Main Window Class
/////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __WIN32APPWINDOW_H__
#define __WIN32APPWINDOW_H__

#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <tchar.h>
/*#ifdef UNICODE
#include <tchar.h>
#endif //UNICODE*/

#define WINDOW_CLASS_NAME_SIZE 256
#define APP_NAME_SIZE  256

class CWin32AppWindow
{
public:
    CWin32AppWindow(HINSTANCE hInstance);
    ~CWin32AppWindow();

    bool CreateAppWindow(const char *name, int width, int height);
    void SetWindow();

    static LRESULT CALLBACK AppWinProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
    void ProcessMessages();

protected:
    BOOL		RegisterAppWindowClass();
    HWND        CreateAppWindow();

    // Window Handlers And Structers
    HINSTANCE   m_hInstance;
    HWND        m_hWnd;
    HDC         m_hDC;
    WNDCLASSEX  m_WndClass;

    TCHAR       m_tstrWindowsClass[WINDOW_CLASS_NAME_SIZE];// Window Class Name String
    TCHAR       m_tstrAppName[APP_NAME_SIZE];// Application Name String

    // Size Of The Window                                           
    int         mWidth;
    int         mHeight;

    // Full Screen Flag
    bool        m_bFullScreen;

private:
    inline void CopyAppNameString(const char *name);
};

#endif //__WIN32APPWINDOW_H__