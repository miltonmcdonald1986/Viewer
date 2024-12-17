#include "GLCanvas.h"

wxBEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
	EVT_PAINT(GLCanvas::OnPaint)
	EVT_SIZE(GLCanvas::OnSize)
wxEND_EVENT_TABLE()

GLCanvas::GLCanvas(wxWindow* parent, wxWindowID id, const int* attribList, const wxPoint& pos, const wxSize& size, long style, const wxString& name, const wxPalette& palette)
	: wxGLCanvas(parent, id, attribList, pos, size, style, name, palette)
{
	wxGLContextAttrs glContextAttrs;
	glContextAttrs.CoreProfile().MajorVersion(3).MinorVersion(3).Robust().ResetIsolation().EndList();
	m_GLContext = new wxGLContext(this, (const wxGLContext*)0, &glContextAttrs);
	wxGLCanvas::SetCurrent(*m_GLContext);

	// Initialize GLEW
	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		wxMessageBox("glewInit failed!", "Error", wxICON_ERROR | wxOK);
		return;
	}

	m_Initialized = true;
}

GLCanvas::~GLCanvas()
{
	delete m_GLContext;
}

void GLCanvas::OnPaint(wxPaintEvent& event)
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SwapBuffers();
}

void GLCanvas::OnSize(wxSizeEvent& event)
{
	auto size = event.GetSize();
	glViewport(0, 0, size.x, size.y);
}
