#include "ViewerMainFrame.h"

ViewerMainFrame::ViewerMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
	m_spEngine = Viewer::CreateEngine();

	m_GlCanvas = new GLCanvas(m_spEngine, this);
	gSizer1->Add(m_GlCanvas, 1, wxEXPAND);

	// The engine has to wait to fully init until after the OpenGL context was created (in the GLCanvas constructor)
	m_spEngine->Init();

	// For a quick check that OpenGL is alive and well, uncomment 
	// this line and a basic triangle will appear on the GLCanvas.
	m_spEngine->HelloTriangle();

	SetSizer(gSizer1);
	Layout();
}
