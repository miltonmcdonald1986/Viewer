#include "ViewerMainFrame.h"

ViewerMainFrame::ViewerMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
	m_spEngine = Viewer::CreateEngine();

	m_GlCanvas = new GLCanvas(m_spEngine, this);
	gSizer1->Add(m_GlCanvas, 1, wxEXPAND);

	SetSizer(gSizer1);
	Layout();
}
