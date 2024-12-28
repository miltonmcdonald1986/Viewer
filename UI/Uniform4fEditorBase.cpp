///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Uniform4fEditorBase.h"

///////////////////////////////////////////////////////////////////////////

Uniform4fEditor::Uniform4fEditor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextName = new wxStaticText( this, wxID_ANY, _("Name"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextName->Wrap( -1 );
	bSizer7->Add( m_staticTextName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_textCtrlName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( m_textCtrlName, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );


	bSizer6->Add( bSizer7, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );

	m_staticTextXRS = new wxStaticText( this, wxID_ANY, _("x,r,s"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticTextXRS->Wrap( -1 );
	bSizer8->Add( m_staticTextXRS, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );

	m_spinCtrlDoubleXRS = new wxSpinCtrlDouble( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 1, 0, 0.01 );
	m_spinCtrlDoubleXRS->SetDigits( 2 );
	bSizer8->Add( m_spinCtrlDoubleXRS, 0, wxALL, 5 );


	bSizer6->Add( bSizer8, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer6 );
	this->Layout();
	bSizer6->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_spinCtrlDoubleXRS->Connect( wxEVT_COMMAND_SPINCTRLDOUBLE_UPDATED, wxSpinDoubleEventHandler( Uniform4fEditor::m_spinCtrlDoubleXRSOnSpinCtrlDouble ), NULL, this );
	m_spinCtrlDoubleXRS->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( Uniform4fEditor::m_spinCtrlDoubleXRSOnTextEnter ), NULL, this );
}

Uniform4fEditor::~Uniform4fEditor()
{
}
