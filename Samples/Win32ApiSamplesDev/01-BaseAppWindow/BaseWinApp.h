/////////////////////////////////////////////////////////////////////////////////////////////
// BaseWinApp.h
//
// Base Window Application
//
/////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Base/Common/Application.h"

/////////////////////////////////////////////////////////////////////////////////////////////
class CBaseWindowApplication : public CApplication
{
public:
    virtual ~CBaseWindowApplication();
    static void CreateSingleton();

protected:
    CBaseWindowApplication();
    
    const char *GetApplicationName();
};

/////////////////////////////////////////////////////////////////////////////////////////////