#pragma once

// MUST include glew.h BEFORE glcanvas.h
#include "GL/glew.h"

#include "wx/frame.h"
#include "wx/glcanvas.h"
#include "wx/msgdlg.h"

class GLCanvas : public wxGLCanvas
{
public:
	GLCanvas(wxWindow* parent, wxWindowID id = wxID_ANY, const int* attribList = NULL, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0, const wxString& name = wxGLCanvasName, const wxPalette& palette = wxNullPalette);

	~GLCanvas();

	// Events
	void OnPaint(wxPaintEvent& event);
	void OnSize(wxSizeEvent& event);

private:
	bool m_Initialized = false;
	wxGLContext* m_GLContext = nullptr;

	wxDECLARE_EVENT_TABLE();
};
