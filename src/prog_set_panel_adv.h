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
#ifndef PROG_SET_PANEL_ADV_H
#define PROG_SET_PANEL_ADV_H

//(*Headers(prog_set_panel_adv)
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/filepicker.h>
#include <wx/stattext.h>
//*)
#include "prog_set_panel.h"

class prog_set_panel_adv: public wxPanel
{
	public:

		prog_set_panel_adv(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~prog_set_panel_adv();

		//(*Declarations(prog_set_panel_adv)
		wxCheckBox* CheckBox1;
		wxStaticText* StaticText1;
		wxDirPickerCtrl* DirPickerCtrl1;
		//*)
		current_settings* set_now;
        wxConfigBase *confi;
		void fill_all(void);
		void Save(void);
	protected:

		//(*Identifiers(prog_set_panel_adv)
		static const long ID_CHECKBOX1;
		static const long ID_STATICTEXT1;
		static const long ID_CUSTOM1;
		//*)

	private:

		//(*Handlers(prog_set_panel_adv)
		void OnCheckBox1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
