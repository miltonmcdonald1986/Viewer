#include "GLCanvas.h"

GLCanvas::GLCanvas(Viewer::IEngineSPtr spEngine, wxWindow* parent, wxWindowID id, const int* attribList, const wxPoint& pos, const wxSize& size, long style, const wxString& name, const wxPalette& palette)
	: wxGLCanvas(parent, id, attribList, pos, size, style, name, palette)
	, m_spEngine(spEngine)
{
	wxGLContextAttrs glContextAttrs;
	glContextAttrs.CoreProfile().MajorVersion(3).MinorVersion(3).Robust().ResetIsolation().EndList();
	m_GLContext = new wxGLContext(this, (const wxGLContext*)0, &glContextAttrs);
	wxGLCanvas::SetCurrent(*m_GLContext);
}

GLCanvas::~GLCanvas()
{
	delete m_GLContext;
}

void GLCanvas::OnLeftDown(wxMouseEvent& event)
{
	float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float g = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	float b = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

	m_spEngine->SetBackgroundColor(r, g, b);
	Refresh();
}

void GLCanvas::OnPaint(wxPaintEvent& event)
{
	m_spEngine->Render();
	SwapBuffers();
}

void GLCanvas::OnSize(wxSizeEvent& event)
{
	auto size = event.GetSize();
	glViewport(0, 0, size.x, size.y);
	Refresh();
}

wxBEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
	EVT_LEFT_DOWN(GLCanvas::OnLeftDown)
	EVT_PAINT(GLCanvas::OnPaint)
	EVT_SIZE(GLCanvas::OnSize)
wxEND_EVENT_TABLE()
