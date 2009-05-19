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
#ifndef DB_SET_PANEL_H
#define DB_SET_PANEL_H

//(*Headers(db_set_panel)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)
#include <wx/config.h>
#include <wx/msgdlg.h>
#include <string>
#include <mysql++.h>
#include <iostream>
#include "wx_std.h"
#include "backup.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>

class db_set_panel: public wxPanel
{
	public:

		db_set_panel(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~db_set_panel();

		//(*Declarations(db_set_panel)
		wxTextCtrl* TextCtrl3;
		wxCheckBox* CheckBox1;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxCheckBox* CheckBox2;
		wxTextCtrl* TextCtrl1;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText2;
		wxTextCtrl* TextCtrl4;
		wxTextCtrl* TextCtrl2;
		//*)
		void Save(void);
        wxConfigBase *confi;
        mysqlpp::Connection * conn;
        void fill_all(void);
        bool dbase_connected;
	protected:

		//(*Identifiers(db_set_panel)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_CHECKBOX2;
		static const long ID_CHECKBOX1;
		//*)

	private:

		//(*Handlers(db_set_panel)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
