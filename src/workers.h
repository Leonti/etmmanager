/*************************************************************************************
*  ETM Manager - works with the time data from the Mysql database. Part of           *
*  ETM (Employee Time Management) project.                                           *
*  Copyright (C) 2008  Leonti Bielski                                                *
*                                                                                    *
*  This program is free software; you can redistribute it and/or modify              *
*  it under the terms of the GNU General Public License as published by              *
*  the Free Software Foundation; either version 2 of the License, or                 *
*  (at your option) any later version.                                               *
*                                                                                    *
*  This program is distributed in the hope that it will be useful,                   *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                    *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                     *
*  GNU General Public License for more details.                                      *
*                                                                                    *
*  You should have received a copy of the GNU General Public License                 *
*  along with this program; if not, write to the Free Software                       *
*  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA    *
*************************************************************************************/
#ifndef WORKERS_H
#define WORKERS_H

//(*Headers(workers)
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
#include <sstream>
#include "wx_std.h"
#include "contracts.h"
#include <wx/dcclient.h>
//#include <sstream>
#include <wx/stdpaths.h>
#include <wx/filename.h>

class workers: public wxDialog
{
	public:

		workers(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~workers();

		//(*Declarations(workers)
		wxListBox* worker_jobs_listbox;
		wxButton* add_job_emp_button;
		wxTextCtrl* w_code_txt;
		wxListBox* ListBox1;
		wxWindow* Image1;
		wxListBox* jobs_listbox;
		wxButton* Button4;
		wxTextCtrl* w_comment_txt;
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* remove_job;
		wxStaticText* StaticText1;
		wxTextCtrl* j_name_txt;
		wxStaticText* StaticText3;
		wxChoice* Choice1;
		wxButton* Button5;
		wxStaticText* StaticText8;
		wxTextCtrl* w_name_txt;
		wxStaticText* StaticText7;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxButton* add_job;
		wxStaticText* StaticText2;
		wxButton* delete_job;
		wxStaticText* StaticText6;
		wxTextCtrl* j_wage_txt;
		wxStaticText* StaticText9;
		wxButton* change_job;
		wxTextCtrl* j_comment_txt;
		//*)

		void fill_all(void);
        mysqlpp::Connection * conn_workers;

	protected:

		//(*Identifiers(workers)
		static const long ID_STATICTEXT9;
		static const long ID_LISTBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_CHOICE1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_BUTTON4;
		static const long ID_WIND1;
		static const long ID_STATICTEXT7;
		static const long ID_LISTBOX2;
		static const long ID_BUTTON5;
		static const long ID_BUTTON6;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL6;
		static const long ID_BUTTON7;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_LISTBOX3;
		static const long ID_BUTTON10;
		//*)

	private:

		//(*Handlers(workers)
		void OnButton4Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnListBox1Select(wxCommandEvent& event);
		void Onjobs_listboxSelect(wxCommandEvent& event);
		void Onadd_jobClick(wxCommandEvent& event);
		void Onchange_jobClick(wxCommandEvent& event);
		void Ondelete_jobClick(wxCommandEvent& event);
		void Onadd_job_emp_buttonClick(wxCommandEvent& event);
		void Onworker_jobs_listboxSelect(wxCommandEvent& event);
		void Onremove_jobClick(wxCommandEvent& event);
		void OnButton1Click1(wxCommandEvent& event);
		void OnImage1Paint(wxPaintEvent& event);
		void OnImage1LeftUp(wxMouseEvent& event);
		//*)
		wxArrayInt workers_ids;
		wxArrayInt jobs_ids;
		wxArrayInt work_job_ids;
		wxArrayInt contractIds;
		wxClientDC* photoDC;
        wxWindow* photoWindow;

		int contractDef;
		void refresh_workers(void);
		void refresh_jobs(void);
		void refreshLimits(void);
		void work_txt_clear(void);
		void job_txt_clear(void);
		void refresh_work_jobs();

		DECLARE_EVENT_TABLE()
};

#endif
