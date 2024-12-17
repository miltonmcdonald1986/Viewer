#pragma once

#include "IEngine.h"

#include "wx/frame.h"
#include "wx/glcanvas.h"
#include "wx/msgdlg.h"

class GLCanvas : public wxGLCanvas
{
public:
	GLCanvas(Viewer::IEngineSPtr spEngine, wxWindow* parent, wxWindowID id = wxID_ANY, const int* attribList = NULL, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxGLCanvasName, const wxPalette& palette = wxNullPalette);

	~GLCanvas();

	// Events
	void OnLeftDown(wxMouseEvent& event);
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);

private:
	Viewer::IEngineSPtr m_spEngine = nullptr;
	wxGLContext* m_GLContext = nullptr;

	wxDECLARE_EVENT_TABLE();
};
