#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "ViewerMainFrame.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};

wxIMPLEMENT_APP(MyApp);

bool MyApp::OnInit()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    
    ViewerMainFrame* frame = new ViewerMainFrame(nullptr);
    frame->Show(true);
    return true;
}
