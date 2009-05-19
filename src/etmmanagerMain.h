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

#ifndef ETMMANAGERMAIN_H
#define ETMMANAGERMAIN_H

//(*Headers(etmmanagerFrame)
#include <wx/grid.h>
#include <wx/sizer.h>
#include <wx/datectrl.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/dateevt.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/choice.h>
//*)

#include "wx_std.h"
#include "settings.h"
#include <wx/msgdlg.h>
#include "backup.h"
#include <datetime.h>
#include <wx/filedlg.h>
#include <string>
#include <mysql++.h>
#include <iostream>
#include <wx/config.h>
#include "workers.h"
#include "round.h"
#include "edit_time.h"
#include "about.h"
#include "contracts.h"
#include <wx/stdpaths.h>
#include <wx/filename.h>
#include "version.h"

struct diffs{
wxTimeSpan duration;
int job_id;
bool isEmpty;
    };
struct jobInfo{
wxString Name;
double Wage;
    };
struct limits{
int weekStarts;
double dayLimit;
double weekLimit;
double multiplier;
    };
WX_DECLARE_OBJARRAY(diffs, diffsArray);
class etmmanagerFrame: public wxFrame
{
    public:

        etmmanagerFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~etmmanagerFrame();

        wxConfigBase *config;
        int connect_to_db(void);

    mysqlpp::Connection * conn;
    wxString host;
    wxString user;
    wxString pass;
    wxString dbase;
    bool dbase_connected;

    private:

        //(*Handlers(etmmanagerFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnMenuItem5Selected(wxCommandEvent& event);
        void OnMenuItem3Selected(wxCommandEvent& event);
        void OnChoice1Select(wxCommandEvent& event);
        void OnDatePickerCtrl1Changed(wxDateEvent& event);
        void OnDatePickerCtrl1Changed1(wxDateEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnGrid1LabelLeftDClick(wxGridEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnMakeBackupMenu(wxCommandEvent& event);
        void OnRestoreFromBackupMenu(wxCommandEvent& event);
        void OnInstallStructureMenu(wxCommandEvent& event);
        void OnEditLimits(wxCommandEvent& event);
        //*)

        //(*Identifiers(etmmanagerFrame)
        static const long ID_DATEPICKERCTRL1;
        static const long ID_DATEPICKERCTRL2;
        static const long ID_BUTTON1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT1;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT6;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT7;
        static const long ID_STATICTEXT4;
        static const long ID_STATICTEXT8;
        static const long ID_STATICTEXT9;
        static const long ID_STATICTEXT16;
        static const long ID_STATICTEXT17;
        static const long ID_STATICTEXT10;
        static const long ID_STATICTEXT11;
        static const long ID_STATICTEXT12;
        static const long ID_STATICTEXT13;
        static const long ID_STATICTEXT14;
        static const long ID_STATICTEXT15;
        static const long ID_PANEL1;
        static const long ID_GRID2;
        static const long ID_GRID1;
        static const long ID_MENUITEM4;
        static const long ID_MENUITEM5;
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long ID_MENUITEM2;
        static const long ID_MENUITEM6;
        static const long ID_MENUITEM3;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(etmmanagerFrame)
        wxStaticText* dayLimit;
        wxPanel* Panel1;
        wxStatusBar* StatusBar1;
        wxStaticText* comment_txt;
        wxStaticText* weekLimit;
        wxMenu* Menu3;
        wxGrid* Grid1;
        wxButton* Button1;
        wxStaticText* weekStarts;
        wxStaticText* StaticText1;
        wxStaticText* StaticText10;
        wxDatePickerCtrl* DatePickerCtrl2;
        wxStaticText* StaticText3;
        wxStaticText* code_static;
        wxMenuItem* MenuItem3;
        wxFlexGridSizer* FlexGridSizer3;
        wxChoice* Choice1;
        wxStaticText* StaticText8;
        wxMenu* Menu4;
        wxStaticText* StaticText7;
        wxStaticText* name_static;
        wxMenuItem* MenuItem5;
        wxStaticText* StaticText4;
        wxStaticText* multiplier;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        wxGrid* Grid2;
        wxMenuItem* MenuItem4;
        wxMenuItem* MenuItem7;
        wxMenuItem* MenuItem6;
        wxStaticText* StaticText6;
        wxStaticText* jobs_txt;
        wxMenuItem* MenuItem8;
        wxDatePickerCtrl* DatePickerCtrl1;
        //*)
        void refresh_workers(void);
        void emp_info(void);
        void write_row(int n, wxString first_t, wxString second_t, wxString& job_n, double diff, double wage, double to_pay, bool colour = false);
        wxArrayInt workers_ids;
        current_settings set_now;
        void read_settings(void);
        wxArrayString dates;
        wxArrayInt dates_ceros;
        diffsArray diffesArr;
        jobInfo getJob(int jobId);
        void writeEmptyRow(int n);
        void clearGridLabels(void);
        void myClearGrid(void);
        wxString vers;
        limits ovLimits;

        wxLocale Locale;
        void readSet(void);
        void checkUpdateDB();

        DECLARE_EVENT_TABLE()
};

#endif // ETMMANAGERMAIN_H
