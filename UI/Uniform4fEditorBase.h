///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/spinctrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// Class Uniform4fEditor
///////////////////////////////////////////////////////////////////////////////
class Uniform4fEditor : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticTextName;
		wxTextCtrl* m_textCtrlName;
		wxStaticText* m_staticTextXRS;
		wxSpinCtrlDouble* m_spinCtrlDoubleXRS;

		// Virtual event handlers, override them in your derived class
		virtual void m_spinCtrlDoubleXRSOnSpinCtrlDouble( wxSpinDoubleEvent& event ) { event.Skip(); }
		virtual void m_spinCtrlDoubleXRSOnTextEnter( wxCommandEvent& event ) { event.Skip(); }


	public:

		Uniform4fEditor( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~Uniform4fEditor();

};

