///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.2.1-0-g80c4cb6)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ViewerBase.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menuUniforms = new wxMenu();
	wxMenuItem* m_menuUniform4f;
	m_menuUniform4f = new wxMenuItem( m_menuUniforms, wxID_ANY, wxString( _("Uniform4f...") ) , wxEmptyString, wxITEM_NORMAL );
	m_menuUniforms->Append( m_menuUniform4f );

	m_menubar1->Append( m_menuUniforms, _("Uniforms") );

	this->SetMenuBar( m_menubar1 );

	gSizer1 = new wxGridSizer( 1, 1, 0, 0 );


	this->SetSizer( gSizer1 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_menuUniforms->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::m_menuUniform4fOnMenuSelection ), this, m_menuUniform4f->GetId());
}

MainFrame::~MainFrame()
{
}
