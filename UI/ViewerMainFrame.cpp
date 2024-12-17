#include "ViewerMainFrame.h"

ViewerMainFrame::ViewerMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
	m_GlCanvas = new GLCanvas(this);
	gSizer1->Add(m_GlCanvas, 1, wxEXPAND);

	SetSizer(gSizer1);
	Layout();
}
