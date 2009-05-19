#ifndef CONTRACTS_H
#define CONTRACTS_H

//(*Headers(contracts)
#include <wx/checkbox.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/listbox.h>
//*)

#include <mysql++.h>
#include <string>
#include <iostream>
#include "wx_std.h"
#include <wx/datetime.h>

class contracts: public wxDialog
{
	public:

		contracts(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~contracts();

		//(*Declarations(contracts)
		wxFlexGridSizer* FlexGridSizer1;
		wxTextCtrl* TextCtrl3;
		wxListBox* ListBox1;
		wxButton* Button4;
		wxButton* Button1;
		wxCheckBox* CheckBox1;
		wxButton* Button2;
		wxButton* Button3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxChoice* Choice1;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl2;
		//*)

		void fillAll(void);
		void clearAll(void);
        mysqlpp::Connection * conn;

	protected:

		//(*Identifiers(contracts)
		static const long ID_STATICTEXT1;
		static const long ID_LISTBOX1;
		static const long ID_STATICTEXT2;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL3;
		static const long ID_CHECKBOX1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		//*)

	private:

		//(*Handlers(contracts)
		void OnButton4Click(wxCommandEvent& event);
		void OnListBox1Select(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		//*)
		wxArrayInt contractIds;
		int defContract;

		DECLARE_EVENT_TABLE()
};

#endif
