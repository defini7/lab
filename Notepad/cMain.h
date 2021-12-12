#pragma once

#include <wx/wx.h>

class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

private:
	wxMenuBar* m_MenuBar = nullptr;
	wxMenu* m_Menu = nullptr;
	wxTextCtrl* m_TextCtrl = nullptr;

	void OnSave(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);

	DECLARE_EVENT_TABLE()
};

