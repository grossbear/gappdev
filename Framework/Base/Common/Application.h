/////////////////////////////////////////////////////////////////////////////////////////////
// Application.h
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Base/AppWindow/AppWindow.h"
#include <string>

enum ButtonType
{
    BTYPE_LBUTTON,
    BTYPE_RBUTTON,
    BTYPE_MBUTTON,
};

class CApplication
{
public:
    static CApplication* GetSingleton();
    virtual ~CApplication();
    
    bool Run(CAppWindow *pAppWnd);
    
    virtual void SetSize(int width, int height) {}
    virtual void KeyDown(unsigned int key) {}
    virtual void KeyUp(unsigned int key) {}
    virtual void Activate(bool active) {}

    virtual void MouseMove(int x, int y) {}
    virtual void MouseButtonDown(ButtonType btype, int x, int y) {}
    virtual void MouseButtonUp(ButtonType btype, int x, int y) {}
    virtual void MouseButtonDblClk(ButtonType btype, int x, int y) {}
    
    virtual bool IsActive() const;
    
    virtual bool RunMainProcess();

    virtual void CloseMsg();
    virtual void QuitMsg();
    
    const char *GetApplicationName() const;
    
protected:  
    CApplication(const char *pstrAppName);
    
    virtual bool StartApp(CAppWindow *pAppWnd);
	virtual bool InitApp();
    virtual bool RunApp();
    virtual bool CloseApp();
    
    virtual bool RunAfterProcess();
    
    //bool RunApplication();
    
    static CApplication *m_pApplication;
    CAppWindow *m_pAppWnd;
    
    //bool m_bKeys[256];
    bool m_bActive;
    bool m_bRunning;
    
private:
    std::string m_strAppName;
};

#endif //__APPLICATION_H__