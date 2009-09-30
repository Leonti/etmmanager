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
#ifndef EDIT_TIME_H
#define EDIT_TIME_H

//(*Headers(edit_time)
#include <wx/grid.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/stattext.h>
//*)
#include <string>
#include <mysql++.h>
#include <iostream>
#include "wx_std.h"
#include <wx/msgdlg.h>

class edit_time: public wxDialog
{
public:

    edit_time(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
    virtual ~edit_time();

    //(*Declarations(edit_time)
    wxFlexGridSizer* FlexGridSizer1;
    wxButton* Button4;
    wxButton* Button1;
    wxGrid* Grid1;
    wxButton* Button2;
    wxButton* Button3;
    wxStaticText* StaticText1;
    //*)
    mysqlpp::Connection * conn;
    void fill_all(wxString& date, int emp_id);
protected:

    //(*Identifiers(edit_time)
    static const long ID_STATICTEXT1;
    static const long ID_GRID1;
    static const long ID_BUTTON1;
    static const long ID_BUTTON2;
    static const long ID_BUTTON3;
    static const long ID_BUTTON4;
    //*)

private:

    //(*Handlers(edit_time)
    void OnButton4Click(wxCommandEvent& event);
    void OnButton1Click(wxCommandEvent& event);
    void OnButton2Click(wxCommandEvent& event);
    void OnButton3Click(wxCommandEvent& event);
    //*)
    wxArrayString jobs;
    wxArrayInt job_ids;

    wxArrayString times;
    wxArrayString job_names;
    wxArrayInt time_ids;
    wxArrayInt to_delete;
    wxDateTime today;
    int employee_id;


    DECLARE_EVENT_TABLE()
};

#endif
