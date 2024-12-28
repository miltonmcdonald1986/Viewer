#include "ViewerMainFrame.h"
#include "Uniform4fEditorUniform4fEditor.h"

ViewerMainFrame::ViewerMainFrame( wxWindow* parent )
:
MainFrame( parent )
{
	m_spEngine = Viewer::CreateEngine();

	m_GLCanvas = new GLCanvas(m_spEngine, this);
	gSizer1->Add(m_GLCanvas, 1, wxEXPAND);

	// The engine has to wait to fully init until after the OpenGL context was created (in the GLCanvas constructor)
	m_spEngine->Init();

	// For a quick check that OpenGL is alive and well, uncomment
	// this line and a basic triangle will appear on the GLCanvas.
	m_spEngine->HelloTriangle();

	SetSizer(gSizer1);
	Layout();

	m_Timer.SetOwner(m_GLCanvas);
	m_Timer.Start(1000/60);
}

void ViewerMainFrame::m_menuUniform4fOnMenuSelection( wxCommandEvent& event )
{
	Uniform4fEditorUniform4fEditor* dlg = new Uniform4fEditorUniform4fEditor(this);
	dlg->Show();
}


ViewerMainFrame::~ViewerMainFrame()
{
	m_Timer.Stop();
}

Viewer::IEngineSPtr ViewerMainFrame::GetEngine()
{
	return m_spEngine;
}

wxGLCanvas* ViewerMainFrame::GetGLCanvas()
{
	return m_GLCanvas;
}
