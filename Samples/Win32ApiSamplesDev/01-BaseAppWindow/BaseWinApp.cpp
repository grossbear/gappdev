/////////////////////////////////////////////////////////////////////////////////////////////
// BaseAppWindow.cpp
//
// Base Window Application
//
/////////////////////////////////////////////////////////////////////////////////////////////

#include "BaseWinApp.h"
#include <stdio.h>

#define APPLICATION_NAME "Base Window Application"


////////////////////////////////////////////////////////////////////////////////////////////
CApplication *CreateApplication(const char *cmdline)
{
    CBaseWindowApplication::CreateSingleton();
    return CBaseWindowApplication::GetSingleton();
}

/////////////////////////////////////////////////////////////////////////////////////////////
void CBaseWindowApplication::CreateSingleton()
{
    if(m_pApplication == NULL) {
        m_pApplication = new CBaseWindowApplication();
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////
CBaseWindowApplication::CBaseWindowApplication():CApplication(APPLICATION_NAME)
{
    printf("BaseWindowApplication constructor\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////
CBaseWindowApplication::~CBaseWindowApplication()
{
    printf("BaseWindowApplication destructor\n");
}

/////////////////////////////////////////////////////////////////////////////////////////////
