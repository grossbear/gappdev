/////////////////////////////////////////////////////////////////////////////////////////////
// Application.cpp
/////////////////////////////////////////////////////////////////////////////////////////////

#include "Application.h"
#include <assert.h>
#include <stdio.h>

#define DEFAULT_WINDOW_WIDTH    640
#define DEFAULT_WINDOW_HEIGHT   480

CApplication *CApplication::m_pApplication = NULL;


/////////////////////////////////////////////////////////////////////////////////////////////
CApplication::CApplication(const char *pstrAppName) : m_pAppWnd(NULL), m_bActive(false), m_bRunning(false)
{
    printf("Creating Application object\n");
    assert(pstrAppName != NULL);
    printf("pstrAppName: %s\n",pstrAppName);
    m_strAppName = std::string(pstrAppName);
}

/////////////////////////////////////////////////////////////////////////////////////////////
CApplication::~CApplication()
{
    printf("Destroing Application object\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::Run(CAppWindow *pAppWnd)
{
    // Run programme
    bool result = this->StartApp(pAppWnd);
    if(!result) return false;

	result = this->InitApp();
	if(!result) return false;

    this->RunApp();

    result = this->CloseApp();

    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////
const char *CApplication::GetApplicationName() const
{
    return m_strAppName.c_str();
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::StartApp(CAppWindow *pAppWnd)
{
    bool result = false;
    if(pAppWnd == NULL)
        return false;
    
    m_pAppWnd = pAppWnd;
    
    result = m_pAppWnd->CreateAppWindow(m_strAppName.c_str(),DEFAULT_WINDOW_WIDTH,DEFAULT_WINDOW_HEIGHT);
    if(result == false)
        return false;
    
    m_bActive = true;
    
    return result;
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::InitApp()
{
    m_pAppWnd->SetWindow();
    
    m_bRunning = true;
    
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::RunApp()
{
    bool result = true;
    
    while(result)
    {
        m_pAppWnd->ProcessMessages();
        result = RunAfterProcess();
    }
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::CloseApp()
{
    m_bActive = false;
    m_bRunning = false;
	m_pAppWnd = NULL;
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::RunAfterProcess()
{
    return false;
}

/////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////
CApplication* CApplication::GetSingleton()
{
    return m_pApplication;
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::IsActive() const
{
    return m_bActive;
}

/////////////////////////////////////////////////////////////////////////////////////////////
bool CApplication::RunMainProcess()
{
    //Running main process...
    
    return m_bRunning;
}

/////////////////////////////////////////////////////////////////////////////////////////////
void CApplication::CloseMsg()
{
    m_bRunning = false;
}
/////////////////////////////////////////////////////////////////////////////////////////////
void CApplication::QuitMsg()
{
    m_bRunning = false;
}

/////////////////////////////////////////////////////////////////////////////////////////////