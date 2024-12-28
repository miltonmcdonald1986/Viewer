#include "Uniform4fEditorUniform4fEditor.h"

Uniform4fEditorUniform4fEditor::Uniform4fEditorUniform4fEditor( wxWindow* parent )
:
Uniform4fEditor( parent )
{

}

void Uniform4fEditorUniform4fEditor::m_spinCtrlDoubleXRSOnSpinCtrlDouble( wxSpinDoubleEvent& event )
{
((ViewerMainFrame*)(GetParent()))->GetEngine()->GetShader("sandbox")->SetUniform("ourColor", glm::vec4(static_cast<float>(m_spinCtrlDoubleXRS->GetValue()), 0.f, 0.f, 1.f));
}

void Uniform4fEditorUniform4fEditor::m_spinCtrlDoubleXRSOnTextEnter( wxCommandEvent& event )
{
// TODO: Implement m_spinCtrlDoubleXRSOnTextEnter
}
