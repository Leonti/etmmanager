/*************************************************************************************
*  ETM Manager - works with the time data from the Mysql database. Part of           *
*  ETM (Employee Time Management) project.                                           *
*  Copyright (C) 2009  Leonti Bielski                                                *
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
#ifndef SETTINGS_H
#define SETTINGS_H

//(*Headers(settings)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/notebook.h>
#include <wx/button.h>
#include <wx/statline.h>
//*)
#include "prog_set_panel_adv.h"
#include "db_set_panel.h"
#include "prog_set_panel.h"
#include <wx/config.h>
//#include <wx/dialog.h>
#include <mysql++.h>

class settings: public wxDialog
{
public:

    settings(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~settings();

    //(*Declarations(settings)
    wxFlexGridSizer* FlexGridSizer1;
    wxButton* Button1;
    wxButton* Button2;
    wxStaticLine* StaticLine1;
    wxNotebook* Notebook1;
    //*)
    wxConfigBase *confi;
    void fill_all(void);
    db_set_panel* db_set;
//       bool reconnect;
    mysqlpp::Connection * conn;
    bool dbase_connected;
    current_settings* set_now;
    prog_set_panel* prog_set;
    prog_set_panel_adv* prog_set_adv;
protected:

    //(*Identifiers(settings)
    static const long ID_NOTEBOOK1;
    static const long ID_STATICLINE1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    //*)

private:

    //(*Handlers(settings)
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    //*)

    DECLARE_EVENT_TABLE()
};

#endif
