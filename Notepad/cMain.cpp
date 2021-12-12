#include "cMain.h"

BEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_MENU(10000, cMain::OnSave)
	EVT_MENU(10001, cMain::OnOpen)
	EVT_MENU(10002, cMain::OnExit)
END_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, wxID_ANY, wxT("github.com/defini7 - Notepad"), wxDefaultPosition, wxSize(800, 600))
{
	this->m_MenuBar = new wxMenuBar();
	this->m_Menu = new wxMenu();
	
	this->m_Menu->Append(10000, wxT("&Save File\tCtrl-S"));
	this->m_Menu->Append(10001, wxT("&Open File\tCtrl-O"));

	this->m_Menu->AppendSeparator();
	this->m_Menu->Append(10002, wxT("E&xit\tCtrl-F4"));

	this->m_MenuBar->Append(m_Menu, wxT("&File"));
	this->SetMenuBar(m_MenuBar);

	this->m_TextCtrl = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_MULTILINE);
}

cMain::~cMain() { }

void cMain::OnSave(wxCommandEvent& event)
{
	wxFileDialog* m_SaveDialog = new wxFileDialog(this, wxT("Save File~"), wxT(""), wxT(""),
		wxT("Text Files (*.txt)|*.txt"));

	int nState = m_SaveDialog->ShowModal();

	if (nState == wxID_OK)
		this->m_TextCtrl->SaveFile(m_SaveDialog->GetPath());
}

void cMain::OnOpen(wxCommandEvent& event)
{
	wxFileDialog* m_OpenDialog = new wxFileDialog(this, wxT("Open File~"), wxT(""), wxT(""),
		wxT("Text Files (*.txt)|*.txt"));

	int nState = m_OpenDialog->ShowModal();

	if (nState == wxID_OK)
		this->m_TextCtrl->LoadFile(m_OpenDialog->GetPath());
}

void cMain::OnExit(wxCommandEvent& event)
{
	this->Destroy();
}
