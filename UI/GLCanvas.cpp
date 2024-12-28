#include "GLCanvas.h"
#include <chrono>

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
	auto now = std::chrono::steady_clock::now();
	auto seconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count()/1000.f;
	float g = (std::sin(seconds) / 2.f) + 0.5f;
	auto spShaderSandbox = m_spEngine->GetShader("sandbox");
	spShaderSandbox->Use();
	//spShaderSandbox->SetUniform("ourColor", glm::vec4(0.f, g, 0.f, 1.f));
	m_spEngine->Render();
	SwapBuffers();
}

void GLCanvas::OnSize(wxSizeEvent& event)
{
	auto size = event.GetSize();
	glViewport(0, 0, size.x, size.y);
	Refresh();
}

void GLCanvas::OnTimer(wxTimerEvent& event)
{
	Refresh();
}

wxBEGIN_EVENT_TABLE(GLCanvas, wxGLCanvas)
	EVT_LEFT_DOWN(GLCanvas::OnLeftDown)
	EVT_PAINT(GLCanvas::OnPaint)
	EVT_SIZE(GLCanvas::OnSize)
	EVT_TIMER(-1, GLCanvas::OnTimer)
wxEND_EVENT_TABLE()
