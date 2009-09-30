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

#include "etmmanagerMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(etmmanagerFrame)
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/artprov.h>
//*)
#include <wx/arrimpl.cpp> // this is a magic incantation which must be done!
WX_DEFINE_OBJARRAY(diffsArray);

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(etmmanagerFrame)
const long etmmanagerFrame::ID_DATEPICKERCTRL1 = wxNewId();
const long etmmanagerFrame::ID_DATEPICKERCTRL2 = wxNewId();
const long etmmanagerFrame::ID_BUTTON1 = wxNewId();
const long etmmanagerFrame::ID_CHOICE1 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT1 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT5 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT2 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT6 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT3 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT7 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT4 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT8 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT9 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT16 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT17 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT10 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT11 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT12 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT13 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT14 = wxNewId();
const long etmmanagerFrame::ID_STATICTEXT15 = wxNewId();
const long etmmanagerFrame::ID_PANEL1 = wxNewId();
const long etmmanagerFrame::ID_GRID2 = wxNewId();
const long etmmanagerFrame::ID_GRID1 = wxNewId();
const long etmmanagerFrame::ID_BUTTON2 = wxNewId();
const long etmmanagerFrame::ID_MENUITEM4 = wxNewId();
const long etmmanagerFrame::ID_MENUITEM5 = wxNewId();
const long etmmanagerFrame::ID_MENUITEM1 = wxNewId();
const long etmmanagerFrame::idMenuQuit = wxNewId();
const long etmmanagerFrame::ID_MENUITEM2 = wxNewId();
const long etmmanagerFrame::ID_MENUITEM6 = wxNewId();
const long etmmanagerFrame::ID_MENUITEM3 = wxNewId();
const long etmmanagerFrame::idMenuAbout = wxNewId();
const long etmmanagerFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(etmmanagerFrame,wxFrame)
    //(*EventTable(etmmanagerFrame)
    //*)
END_EVENT_TABLE()



etmmanagerFrame::etmmanagerFrame(wxWindow* parent,wxWindowID id)
{
    readSet();

    vers << AutoVersion::MAJOR << _T(".") << AutoVersion::MINOR << _T(".") << AutoVersion::BUILD;
    //(*Initialize(etmmanagerFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxFlexGridSizer* FlexGridSizer4;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxFlexGridSizer* FlexGridSizer5;

    Create(parent, wxID_ANY, _("ETM manager"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
    {
        wxIcon FrameIcon;
        FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_NORMAL_FILE")),wxART_FRAME_ICON));
        SetIcon(FrameIcon);
    }
    FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(4, 1, 0, 0);
    FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
    DatePickerCtrl1 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
    DatePickerCtrl1->SetToolTip(_("Beginning date"));
    FlexGridSizer4->Add(DatePickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DatePickerCtrl2 = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
    DatePickerCtrl2->SetToolTip(_("Ending date"));
    FlexGridSizer4->Add(DatePickerCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(this, ID_BUTTON1, _("Get info"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->SetToolTip(_("Get time and job information for selected employee in a selected period of time"));
    FlexGridSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(183,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    Choice1->SetToolTip(_("Select an employee"));
    FlexGridSizer2->Add(Choice1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(16,136), wxSize(344,328), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer5 = new wxFlexGridSizer(7, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Name:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer5->Add(StaticText1, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    name_static = new wxStaticText(Panel1, ID_STATICTEXT5, wxEmptyString, wxDefaultPosition, wxSize(128,16), 0, _T("ID_STATICTEXT5"));
    FlexGridSizer5->Add(name_static, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Code:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer5->Add(StaticText2, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    code_static = new wxStaticText(Panel1, ID_STATICTEXT6, wxEmptyString, wxDefaultPosition, wxSize(64,16), 0, _T("ID_STATICTEXT6"));
    FlexGridSizer5->Add(code_static, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Comment:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer5->Add(StaticText3, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    comment_txt = new wxStaticText(Panel1, ID_STATICTEXT7, wxEmptyString, wxDefaultPosition, wxSize(224,64), 0, _T("ID_STATICTEXT7"));
    FlexGridSizer5->Add(comment_txt, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Jobs:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer5->Add(StaticText4, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    jobs_txt = new wxStaticText(Panel1, ID_STATICTEXT8, wxEmptyString, wxDefaultPosition, wxSize(224,152), 0, _T("ID_STATICTEXT8"));
    FlexGridSizer5->Add(jobs_txt, 0, wxALIGN_LEFT|wxALIGN_TOP, 0);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Overtime limits:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
    wxFont StaticText5Font(13,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    FlexGridSizer5->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer5->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT16, _("Week starts from:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    FlexGridSizer5->Add(StaticText7, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    weekStarts = new wxStaticText(Panel1, ID_STATICTEXT17, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
    FlexGridSizer5->Add(weekStarts, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Day limit:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    FlexGridSizer5->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    dayLimit = new wxStaticText(Panel1, ID_STATICTEXT11, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
    FlexGridSizer5->Add(dayLimit, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT12, _("Week limit:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    FlexGridSizer5->Add(StaticText8, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    weekLimit = new wxStaticText(Panel1, ID_STATICTEXT13, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
    FlexGridSizer5->Add(weekLimit, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT14, _("Overtime multiplier:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    FlexGridSizer5->Add(StaticText10, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    multiplier = new wxStaticText(Panel1, ID_STATICTEXT15, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
    FlexGridSizer5->Add(multiplier, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer5);
    FlexGridSizer5->SetSizeHints(Panel1);
    FlexGridSizer2->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Grid2 = new wxGrid(this, ID_GRID2, wxDefaultPosition, wxSize(-1,-1), wxSUNKEN_BORDER|wxNO_BORDER, _T("ID_GRID2"));
    Grid2->CreateGrid(3,2);
    Grid2->SetMinSize(wxSize(-1,-1));
    Grid2->SetMaxSize(wxSize(-1,-1));
    Grid2->SetToolTip(_("Totals for hours and payment"));
    Grid2->EnableEditing(true);
    Grid2->EnableGridLines(true);
    Grid2->SetDefaultCellFont( Grid2->GetFont() );
    Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
    FlexGridSizer2->Add(Grid2, 1, wxALL|wxALIGN_BOTTOM|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(1, 1, 0, 0);
    Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxSize(555,-1), wxSUNKEN_BORDER|wxNO_BORDER, _T("ID_GRID1"));
    Grid1->CreateGrid(20,6);
    Grid1->SetToolTip(_("Double click on a date to change hours"));
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    FlexGridSizer3->Add(Grid1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Print"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer3->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem6 = new wxMenuItem(Menu1, ID_MENUITEM4, _("Make backup"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem6);
    MenuItem7 = new wxMenuItem(Menu1, ID_MENUITEM5, _("Restore from backup"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem7);
    MenuItem4 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Install structure"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    Menu1->AppendSeparator();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu3 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu3, ID_MENUITEM2, _("Employees"), _("Edit list of employees and jobs assigned to them"), wxITEM_NORMAL);
    Menu3->Append(MenuItem3);
    MenuItem8 = new wxMenuItem(Menu3, ID_MENUITEM6, _("Overtime limits"), wxEmptyString, wxITEM_NORMAL);
    Menu3->Append(MenuItem8);
    MenuBar1->Append(Menu3, _("Edit"));
    Menu4 = new wxMenu();
    MenuItem5 = new wxMenuItem(Menu4, ID_MENUITEM3, _("General"), _("Edit database and program settings"), wxITEM_NORMAL);
    Menu4->Append(MenuItem5);
    MenuBar1->Append(Menu4, _("Settings"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_DATEPICKERCTRL1,wxEVT_DATE_CHANGED,(wxObjectEventFunction)&etmmanagerFrame::OnDatePickerCtrl1Changed);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&etmmanagerFrame::OnButton1Click);
    Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnChoice1Select);
    Connect(ID_GRID1,wxEVT_GRID_LABEL_LEFT_DCLICK,(wxObjectEventFunction)&etmmanagerFrame::OnGrid1LabelLeftDClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&etmmanagerFrame::OnButton2Click1);
    Connect(ID_MENUITEM4,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnMakeBackupMenu);
    Connect(ID_MENUITEM5,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnRestoreFromBackupMenu);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnInstallStructureMenu);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnQuit);
    Connect(ID_MENUITEM2,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnMenuItem3Selected);
    Connect(ID_MENUITEM6,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnEditLimits);
    Connect(ID_MENUITEM3,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnMenuItem5Selected);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&etmmanagerFrame::OnAbout);
    //*)

    SetTitle(_T("ETM manager ") + vers);


    dbase_connected = false;
    conn = new mysqlpp::Connection(false);


    connect_to_db();

//doing grids
    Grid1->SetColLabelValue(0,_("Time In"));
    Grid1->SetColLabelValue(1,_("Time Out"));
    Grid1->SetColLabelValue(2,_("Job"));
    Grid1->SetColLabelValue(3,_("Duration"));
    Grid1->SetColLabelValue(4,_("Wage"));
    Grid1->SetColLabelValue(5,_("To pay"));

    Grid1->SetRowLabelSize(85);
    Grid1->SetColSize(0,90);
    Grid1->SetColSize(1,90);
    Grid1->SetColSize(2,100);
    Grid1->SetColSize(3,70);
    Grid1->SetColSize(4,50);
    Grid1->SetColSize(5,60);

//Grid1->AutoSizeColumns();
    Grid1->EnableEditing(false);

    Grid2->SetColLabelValue(0,_("Hours"));
    Grid2->SetColLabelValue(1,_("Earned"));
    Grid2->SetRowLabelValue(0,_("Regular Time:"));
    Grid2->SetRowLabelValue(1,_("Overtime:"));
    Grid2->SetRowLabelValue(2,_("Total Time:"));
    Grid2->SetRowLabelSize(120);
    Grid2->SetCellBackgroundColour(1,0,*wxRED);
    Grid2->SetCellBackgroundColour(1,1,*wxRED);
    Grid2->EnableEditing(false);
//end doing grids


    refresh_workers();
    DatePickerCtrl2->SetRange(DatePickerCtrl1->GetValue(),wxDateTime::Now());
    clearGridLabels();
}

void etmmanagerFrame::readSet(void)
{
    set_now.useBin = false; //we don't use user-defined mysqldir by default
    conn = new mysqlpp::Connection(false);

    config = new wxConfig(_T("etmmanager"));
    set_now.lang = 0;
    wxString lng = config->Read(_T("program/lang"));
    if(lng!=_T(""))
    {
        long temp;
        lng.ToLong(&temp);
        set_now.lang = temp;
    }

    if (config->Read(_T("/program/run")) !=_T("1") || config->Read(_T("/program/run_again")) == _T("1"))
    {
        settings* set_dlg = new settings(this);
        set_dlg -> confi = config;
        set_dlg -> conn = conn;
        set_dlg -> set_now = &set_now;
        set_dlg -> fill_all();
        set_dlg -> ShowModal();
        delete set_dlg;
    }
    else
    {
        read_settings();
    }

    if(set_now.lang != 0)
    {
        Locale.Init(set_now.lang, wxLOCALE_CONV_ENCODING);
        wxLocale::AddCatalogLookupPathPrefix(wxT("./lang"));
        // Initialize the catalogs we'll be using
        Locale.AddCatalog(wxT("etmmanager"));
    }
}


int  etmmanagerFrame::connect_to_db(void)
{

    host = config->Read(_T("/mysql/host"));
    user = config->Read(_T("/mysql/user"));
    pass = config->Read(_T("/mysql/pass"));
    dbase = config->Read(_T("/mysql/dbase"));



    if (conn->connect(wx2std(dbase,wxConvUI).c_str(),wx2std(host,wxConvUI).c_str(),wx2std(user,wxConvUI).c_str(),wx2std(pass,wxConvUI).c_str()))
    {
        StatusBar1->SetStatusText(_("Connected to database '") + dbase + _("' on ") + host,0);
        dbase_connected = true;

        checkUpdateDB(); //checking for the version of the database

        return 0;
    }
    else
    {
        StatusBar1->SetStatusText(_("Unable no connect to database '") + dbase + _("' on ") + host,0);

        wxMessageBox(_("Unable to connect to the database. Reason:\n") + std2wx(conn -> error(),wxConvUI),_("Not connected."), wxOK);
        dbase_connected = false;
        return 1;
    }



}

etmmanagerFrame::~etmmanagerFrame()
{
    //(*Destroy(etmmanagerFrame)
    //*)
}

void etmmanagerFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void etmmanagerFrame::OnAbout(wxCommandEvent& event)
{
    about* about_dlg = new about(this);
    about_dlg->Show();
}

void etmmanagerFrame::OnMenuItem5Selected(wxCommandEvent& event)
{
    settings* set_dlg = new settings(this);
    set_dlg -> confi = config;
    if(dbase_connected == true)
    {
        set_dlg -> dbase_connected = true;
    }
    set_dlg -> conn = conn;
    set_dlg -> set_now = &set_now;
    set_dlg -> fill_all();
    set_dlg -> ShowModal();

    if (
        host != config->Read(_T("/mysql/host")) ||
        user != config->Read(_T("/mysql/user")) ||
        pass != config->Read(_T("/mysql/pass")) ||
        dbase != config->Read(_T("/mysql/dbase"))
    )
    {
        connect_to_db();
    }
    read_settings();
    refresh_workers();
}

void etmmanagerFrame::OnMenuItem3Selected(wxCommandEvent& event)
{
    workers* work_dlg = new workers(this);
    work_dlg -> conn_workers = conn;
    work_dlg -> fill_all();
    work_dlg -> ShowModal();
    refresh_workers();
}
void etmmanagerFrame::refresh_workers()
{
    Choice1 -> Clear();
    name_static->SetLabel(_T(""));
    code_static->SetLabel(_T(""));
    comment_txt->SetLabel(_T(""));
    jobs_txt->SetLabel(_T(""));
    weekStarts->SetLabel(_T(""));
    dayLimit->SetLabel(_T(""));
    weekLimit->SetLabel(_T(""));
    multiplier->SetLabel(_T(""));

    workers_ids.Clear();
    mysqlpp::Query query = conn -> query();
    query << "SELECT * FROM `employees`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            std::string work_name = std::string(row["emp_name"]);
            Choice1->Append(std2wx(work_name, wxConvUI));
            workers_ids.Add(int(row["emp_id"]));
        }
    }

    Choice1->SetSelection(0);
    emp_info();
}

void etmmanagerFrame::emp_info()
{
    ovLimits.dayLimit = 0;
    ovLimits.multiplier = 0;
    ovLimits.weekLimit = 0;
    ovLimits.weekStarts = 0;

    if(workers_ids.GetCount() != 0)
    {

        int contractId = 0;
        mysqlpp::Query query = conn->query();

        query << "SELECT * FROM `employees` WHERE `emp_id`=" << workers_ids[Choice1 -> GetSelection()] << " LIMIT 1";
        mysqlpp::StoreQueryResult res = query.store();
        if (res)
        {
            mysqlpp::Row row = res.at(0);
            name_static -> SetLabel(std2wx(std::string(row["emp_name"]),wxConvUI));
            code_static -> SetLabel(std2wx(std::string(row["emp_ssn"]),wxConvUI));
            comment_txt -> SetLabel(std2wx(std::string(row["emp_comment"]),wxConvUI));
            contractId = int(row["contract_id"]);
        }

        query << "SELECT * FROM `emp_jobs` WHERE `emp_id`=" << workers_ids[Choice1 -> GetSelection()];
        res = query.store();
        if (res)
        {
            wxString jobs;
            mysqlpp::Row row;
            mysqlpp::StoreQueryResult::size_type i;
            for (i = 0; i < res.num_rows(); ++i)
            {
                row = res[i];
                query << "SELECT `job_title` FROM `jobs` WHERE `job_id`='"<< int(row["job_id"]) <<"' LIMIT 1";
                mysqlpp::StoreQueryResult res2 = query.store();
                mysqlpp::Row row2 = res2.at(0);
                jobs << std2wx(std::string(row2["job_title"]), wxConvUI) << _T("\n");

            }
            jobs_txt -> SetLabel(jobs);

        }

        if(contractId !=0 )
        {
            query << "SELECT * FROM `contracts` WHERE `id`='" << contractId << "' LIMIT 1";
        }
        else
        {
            query << "SELECT * FROM `contracts` WHERE `default`='1' LIMIT 1";
        }
        res = query.store();
        if (res)
        {
            mysqlpp::Row row = res.at(0);
            ovLimits.weekStarts = int(row["week_starts"]);
            wxDateTime::WeekDay day = wxDateTime::WeekDay(ovLimits.weekStarts);
            weekStarts ->  SetLabel(wxDateTime::GetWeekDayName(day));
            ovLimits.dayLimit = float(row["day_limit"]);
            ovLimits.weekLimit = float(row["week_limit"]);
            ovLimits.multiplier = float(row["multiplier"]);
            wxString temp;
            temp << ovLimits.dayLimit;
            dayLimit -> SetLabel(temp);
            temp.Clear();
            temp << ovLimits.weekLimit;
            weekLimit -> SetLabel(temp);
            temp.Clear();
            temp << ovLimits.multiplier;
            multiplier -> SetLabel(temp);
        }



    }
}

void etmmanagerFrame::OnChoice1Select(wxCommandEvent& event)
{
    emp_info();
}

void etmmanagerFrame::OnDatePickerCtrl1Changed(wxDateEvent& event)
{
    DatePickerCtrl2->SetRange(DatePickerCtrl1->GetValue(),wxDateTime::Now());
}


void etmmanagerFrame::OnButton1Click(wxCommandEvent& event)
{
    diffesArr.Clear();
    wxDateTime start_date = DatePickerCtrl1->GetValue();
    wxDateTime end_date = DatePickerCtrl2->GetValue();
    end_date.Add(wxTimeSpan::Day());
    mysqlpp::Query query = conn->query();
    wxDateTime toPutDate = start_date;//we will need it later to fill out the grid

    int job_id_yesterday = 0;

//getting info for the last entry of previous day
    wxDateTime mysql_yesterday = start_date;
    mysql_yesterday.Subtract(wxTimeSpan::Day());
    query << "SELECT * FROM `time` WHERE `time_time` > '"<< wx2std(mysql_yesterday.FormatISODate(),wxConvUI) <<"' AND `time_time` < '"<< wx2std(start_date.FormatISODate(),wxConvUI) <<"' AND `time_emp_id` = '"<< workers_ids[Choice1->GetSelection()] <<"' ORDER BY `time_time` DESC LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
    if(res.num_rows() != 0)
    {
        mysqlpp::Row row = res.at(0);
        job_id_yesterday = int(row["time_job_id"]);
    }



    while(start_date <= end_date)
    {
        wxDateTime mysql_date = start_date; //we don't wannt to modify start date
        mysql_date.Add(wxTimeSpan::Day());
        query << "SELECT * FROM `time` WHERE `time_time` > '"<< wx2std(start_date.FormatISODate(),wxConvUI) <<"' AND `time_time` < '"<< wx2std(mysql_date.FormatISODate(),wxConvUI) <<"' AND `time_emp_id` = '"<< workers_ids[Choice1->GetSelection()] <<"' ORDER BY `time_time` ASC";
        start_date = mysql_date; //after we've got info we can increase start date for one more day

        mysqlpp::StoreQueryResult res = query.store();
        if (res)
        {
            diffs diffes;
            if(res.num_rows() != 0)  //we have some entries for this day
            {
                mysqlpp::Row row0;
                mysqlpp::Row row;
                mysqlpp::StoreQueryResult::size_type i;
                for (i = 0; i < res.num_rows(); ++i)
                {
                    row = res[i];
                    if(i !=0)  //we are already on second or higher entry - can subtract previous time
                    {
                        row0 = res.at(i-1);
                        wxDateTime first_time;
                        wxDateTime second_time;
                        first_time.ParseDateTime(std2wx(std::string(row0["time_time"]), wxConvUI).c_str());
                        second_time.ParseDateTime(std2wx(std::string(row["time_time"]), wxConvUI).c_str());

                        diffes.duration = second_time.Subtract(first_time);
                        diffes.job_id = row0["time_job_id"];
                        diffesArr.Add(diffes);
                    }
                    else   // i = 0 this is our first row - using job_id_yesterday getting info from 00:00:00 to the first entry
                    {
                        wxDateTime beginning;
                        beginning.ParseDateTime(std2wx(std::string(row["time_time"]), wxConvUI).c_str());
                        wxDateTime ending = beginning;
                        beginning.ResetTime();  //wxDateTime modyfies object when subtracting or adding values, so we have to copy them before
                        //beginning - 00:00:00 the same date
                        //ending - time of first entry - same day, job_id is job_id_yesterday
                        diffes.duration = ending.Subtract(beginning);
                        diffes.job_id = job_id_yesterday;
                        diffes.isEmpty = false;
                        diffesArr.Add(diffes);
                    }
                    if(i == res.num_rows() - 1)  //this means this is the last entry for today
                    {
                        //i can be 0 - only one row(res.num_rows==1) or more - (res.num_rows > 1)
                        //we need this to get last job (in most cases it's OFF)
                        wxDateTime beginning;
                        beginning.ParseDateTime(std2wx(std::string(row["time_time"]), wxConvUI).c_str());
                        wxDateTime ending = beginning;
                        ending.Add(wxTimeSpan::Day());
                        ending.ResetTime();             //now we have beginning with the time of the last job
                        //and ending with the 00:00:00 of the next day
                        diffes.duration = ending.Subtract(beginning);
                        diffes.job_id = row["time_job_id"];
                        diffes.isEmpty = false;
                        diffesArr.Add(diffes);
                        job_id_yesterday = diffes.job_id;
                    }
                }
            }
            else  //we have empty days - res.num_rows == 0 - adding empty day to diffesArr
            {
                wxDateTime beginning = start_date;
                wxDateTime ending = beginning;
                ending.Add(wxTimeSpan::Day());
                diffes.duration = ending.Subtract(beginning); //filling 24 hours with duration of the last logged job
                diffes.job_id = job_id_yesterday; //this means that someone can work a copuple of days without logging out
                diffes.isEmpty = true;
                diffesArr.Add(diffes); //impossible in practice but for the consistency
            }
        }
    }

//at this point we should have array diffesArr filled with times and jobs without any holes - time to time


    int n = 0; // grid rows
    dates.Clear();
    dates_ceros.Clear();


    double ov_week_limit = ovLimits.weekLimit;
    double ov_day_limit = ovLimits.dayLimit;
    int w_starts = ovLimits.weekStarts; // 0 - Sunday, 6 - Saturday 0 means that on Saturday is still overtime and on Sunday not
    double ov_wage = ovLimits.multiplier;


    bool day_new_overtime = true;

    double hours_this_week = 0;
    bool colour = true;

    double regHoursTotal = 0;
    double overtimeHoursTotal = 0;
    double toPayTotal = 0;
    double toPayOvertime = 0;

    myClearGrid();
    start_date = toPutDate;
    int j = 0;
    bool same_day = true;
    wxString day_label;

    while(start_date < end_date)   //doing it again but this time filling the grid
    {
//bool first_label = true;

        if(start_date.GetWeekDay() == w_starts && !same_day)  //new week starts so reseting overtimes
        {
            hours_this_week = 0;
            day_new_overtime = true;
        }
        double hours_this_day = 0;  //reseting hours for today
        bool hour_new_overtime = true;





        wxDateTime first = start_date;       //we could do it all first time but it's already complicated as it is ;)
        start_date.Add(diffesArr[j].duration);
        if(start_date.FormatISODate() == first.FormatISODate())
        {
            same_day = true;
        }
        else
        {
            same_day = false;
        }

        if(diffesArr[j].isEmpty && diffesArr[j].job_id == 0)  //this means the whole day was day off
        {
            writeEmptyRow(n);
            Grid1->SetRowLabelValue(n, first.FormatDate());
            dates.Add(first.FormatISODate());
            n++;
        }
        else   //filling day as usual
        {
            if(diffesArr[j].job_id != 0)  //we don't need row with OFF value
            {
                if(first.FormatDate() != day_label)
                {
                    day_label = first.FormatDate();
                    Grid1->SetRowLabelValue(n, day_label);
                    dates.Add(first.FormatISODate());
                    dates_ceros.Add(1);
                    if(colour) colour = false;
                    else colour = true;
                }
                else
                {
                    Grid1->SetRowLabelValue(n, _T(""));
                    dates_ceros.Add(0);
                }

                jobInfo jobInf = getJob(diffesArr[j].job_id);
                double diff = diffesArr[j].duration.GetSeconds().ToDouble()/3600;
                hours_this_week += diff;
                hours_this_day += diff;
                double wage = jobInf.Wage;

                if(hours_this_week <= ov_week_limit && hours_this_day <= ov_day_limit)  //below the overtimes
                {
                    double to_pay = wage*diff;
                    write_row(n, first.FormatTime(), start_date.FormatTime(), jobInf.Name, diff ,wage, to_pay,colour);
                    toPayTotal += round_2(to_pay);
                    regHoursTotal += round_2(diff);
                    n++;
                }
                else  //overtime is on
                {

                    double brea_time;
                    if(hours_this_week > ov_week_limit)
                    {
                        brea_time = hours_this_week - ov_week_limit;
                    }
                    else
                    {
                        brea_time = hours_this_day - ov_day_limit;
                    }

                    bool divide_day = false;
                    if(day_new_overtime && hours_this_week > ov_week_limit)
                    {
                        divide_day = true;
                        day_new_overtime = false;
                    }
                    else if(hour_new_overtime && hours_this_day > ov_day_limit && hours_this_week <= ov_week_limit)
                    {
                        divide_day = true;
                        hour_new_overtime = false;
                    }
                    wxDateTime first_time = first;
                    wxDateTime second_time = start_date;

                    if(divide_day)
                    {
                        double t_p_normal = (diff - brea_time)*wage;
                        wxTimeSpan ov_diff(0,0,((diff - brea_time)*3600),0);
                        second_time = first_time;
                        write_row(n, first_time.FormatTime(),second_time.Add(ov_diff).FormatTime(), jobInf.Name,(diff - brea_time), wage, t_p_normal, colour);
                        toPayTotal += round_2(t_p_normal);
                        regHoursTotal += round_2(diff - brea_time);
                        n++;

                        double t_p = brea_time*ov_wage*wage;
                        wxTimeSpan ov_diff2(0,0,((brea_time)*3600),0);
                        wxDateTime third_time = second_time;
                        write_row(n, second_time.FormatTime(),third_time.Add(ov_diff2).FormatTime(), jobInf.Name, brea_time, (wage*ov_wage), t_p, colour);
                        toPayOvertime += round_2(t_p);
                        overtimeHoursTotal += round_2(brea_time);
                        Grid1->SetRowLabelValue(n, _T(""));
                        dates_ceros.Add(0);
                        Grid1->SetCellBackgroundColour(n,5,*wxRED);
                        n++;
                    }
                    else
                    {
                        double t_p = diff*ov_wage*wage;
                        write_row(n, first_time.FormatTime(),second_time.FormatTime(), jobInf.Name, diff, (wage*ov_wage), t_p, colour);
                        toPayOvertime += round_2(t_p);
                        overtimeHoursTotal += round_2(diff);
                        Grid1->SetCellBackgroundColour(n,5,*wxRED);
                        n++;
                    }

                }


            }
        }
        j++; //adding first difference and increasing position in differArr

    }


    wxString temp;
    temp << regHoursTotal;
    Grid2->SetCellValue(0,0,temp);
    temp.Clear();
    temp << overtimeHoursTotal;
    Grid2->SetCellValue(1,0,temp);
    temp.Clear();
    temp << (regHoursTotal + overtimeHoursTotal);
    Grid2->SetCellValue(2,0,temp);
    temp.Clear();
    temp << toPayTotal;
    Grid2->SetCellValue(0,1,temp);
    temp.Clear();
    temp << toPayOvertime;
    Grid2->SetCellValue(1,1,temp);
    temp.Clear();
    temp << (toPayTotal + toPayOvertime);
    Grid2->SetCellValue(2,1,temp);

}

jobInfo etmmanagerFrame::getJob(int jobId)
{
    jobInfo jobInf;
    jobInf.Wage = 0;
    jobInf.Name = _("OFF");
    mysqlpp::Query query = conn->query();
    query << "SELECT * FROM `jobs` WHERE `job_id`='"<< jobId <<"' LIMIT 1";
    mysqlpp::StoreQueryResult res = query.store();
    if(res)
    {
        mysqlpp::Row row = res.at(0);
        if(jobId != 0)
        {
            jobInf.Wage = double(row["job_wage"]);
            jobInf.Name = std2wx(std::string(row["job_title"]), wxConvUI);
        }
    }
    return jobInf;
}

void etmmanagerFrame::write_row(int n, wxString first_t, wxString second_t, wxString& job_n, double diff, double wage, double to_pay, bool colour)
{
    if(n>19) Grid1->AppendRows(1);
    Grid1->SetCellValue(n, 0, first_t);
    Grid1->SetCellValue(n, 1, second_t);
    Grid1->SetCellValue(n, 2, job_n);
    wxString temp;
    temp << round_2(diff);
    Grid1->SetCellValue(n, 3, temp);
    temp.Clear();
    temp << wage;
    Grid1->SetCellValue(n, 4, temp);
    temp.Clear();
    temp << round_2(to_pay);
    Grid1->SetCellValue(n,5, temp);
    if(colour)
    {
        wxColor colotemp = *wxLIGHT_GREY;
        for(int i=0; i<6; i++)
        {

            Grid1->SetCellBackgroundColour(n,i, colotemp);
        }
    }
}
void etmmanagerFrame::writeEmptyRow(int n)
{
    if(n>19) Grid1->AppendRows(1);
    dates_ceros.Add(1);
    Grid1->SetCellSize(n,0,1,6);
    Grid1->SetCellAlignment(n, 0, wxALIGN_CENTRE, wxALIGN_CENTRE);
    Grid1->SetCellValue(n,0,_("no entry"));
    Grid1->SetCellBackgroundColour(n,0,*wxCYAN);
}

void etmmanagerFrame::read_settings()
{
    set_now.mysqlBin = config->Read(_T("/program/mysqldir"));
    if(config->Read(_T("/program/usebin"))==_T("1"))
        set_now.useBin = true;
    else
        set_now.useBin = false;
}



void etmmanagerFrame::OnGrid1LabelLeftDClick(wxGridEvent& event)
{
    if(dates.GetCount() != 0)
    {
        int row = event.GetRow();

        int j = 0;
        for(int i=0; i <= row; i++)
        {
            if(dates_ceros[i] == 1) j++;
        }
//wxMessageBox(dates[j-1]);
        edit_time* edit_dlg = new edit_time(this);
        edit_dlg -> conn = conn;
        edit_dlg -> fill_all(dates[j-1], workers_ids[Choice1->GetSelection()]);
        edit_dlg -> ShowModal();
    }
}

void etmmanagerFrame::clearGridLabels()
{
    for(int i=0; i<20; i++)
    {
        Grid1->SetRowLabelValue(i, _T(""));
    }
}
void etmmanagerFrame::myClearGrid()
{
    Grid1->ClearGrid();
    clearGridLabels();
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<6; j++)
        {
            Grid1->SetCellBackgroundColour(i,j,*wxWHITE);
            Grid1->SetCellSize(i,j,1,1);
        }
    }
    Grid1->DeleteRows(20, Grid1->GetNumberRows()-20);
    Grid1->Refresh();
}

void etmmanagerFrame::OnMakeBackupMenu(wxCommandEvent& event)
{
    //make backup
    if(dbase_connected)
    {
        wxFileDialog* save_file_dlg = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_SAVE, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
        save_file_dlg -> ShowModal();
        if(save_file_dlg->GetFilename() != _(""))
        {
//    wxString result;
            int result = makeDump(conn, save_file_dlg -> GetPath());
            if(result == 0) wxMessageBox(_("There was a problem. Backup is not done."));
        }
    }
    else
    {
        wxMessageBox(_("You are not connected to the database!"));
    }
}

void etmmanagerFrame::OnRestoreFromBackupMenu(wxCommandEvent& event)
{
    //rstore from backup
    if(dbase_connected)
    {
        wxFileDialog* open_file_dlg = new wxFileDialog(this, _("Select file"), wxEmptyString, wxEmptyString, wxFileSelectorDefaultWildcardStr, wxFD_DEFAULT_STYLE|wxFD_OPEN, wxDefaultPosition, wxDefaultSize, _T("wxFileDialog"));
        open_file_dlg -> ShowModal();
        if(open_file_dlg->GetFilename() != _(""))
        {
            // wxString result;
            int result = restoreFromDump(conn, open_file_dlg -> GetPath());
            if(result == 0) wxMessageBox(_("There was a problem. Data is not restored."));
        }
    }
    else
    {
        wxMessageBox(_("You are not connected to the database!"));
    }
}

void etmmanagerFrame::OnInstallStructureMenu(wxCommandEvent& event)
{

    if(dbase_connected)
    {

//   int result = restore_table(host, user, pass, dbase, _("table_schema.sql"));
        wxStandardPaths path;
        wxFileName tableName;
        tableName.Assign(path.GetDataDir(),_T("table_schema.sql"));
        int result = restoreFromDump(conn, tableName.GetFullPath());

        if(result == 0) wxMessageBox(_("There was a problem. Database structure is not installed"));

    }
    else
    {
        wxMessageBox(_("You are not connected to the database!"));
    }
}

void etmmanagerFrame::OnEditLimits(wxCommandEvent& event)
{
    contracts* limitsDlg = new contracts(this);
    limitsDlg->conn = conn;
    limitsDlg->fillAll();
    limitsDlg->ShowModal();
    refresh_workers();
}

bool etmmanagerFrame::printTable(wxString& htmlTable)
{

    wxHtmlEasyPrinting* print = new wxHtmlEasyPrinting();
    if(print->PrintText( htmlTable ))
    {
        return 1;
    }
    else
        return 0;
}

void etmmanagerFrame::checkUpdateDB()
{
    bool message = false;
    //checking for 0.5.0 database
    mysqlpp::Query query = conn -> query();
    query << "SHOW TABLES";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        if( res.num_rows() == 4)  //that means we have old database version - we need to add new tables:
        {
            query << "CREATE TABLE IF NOT EXISTS `contracts` (\
  `id` int(11) NOT NULL auto_increment,\
  `week_starts` int(11) NOT NULL,\
  `day_limit` float NOT NULL,\
  `week_limit` float NOT NULL,\
  `multiplier` float NOT NULL,\
  `default` tinyint(1) NOT NULL default '0',\
  PRIMARY KEY  (`id`)\
) ENGINE=MyISAM  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=1";
            query.execute();


            query << "INSERT INTO `contracts` (`id`, `week_starts`, `day_limit`, `week_limit`, `multiplier`, `default`) VALUES (1, 0, 12, 40, 1.5, 1)";
            query.execute();

            query << "ALTER TABLE `employees` ADD `contract_id` INT NOT NULL DEFAULT '0' AFTER `emp_ssn`";
            query.execute();

            message = true;
        }

    }
//checking for 0.6.1 database
    query << "SELECT * FROM `employees` LIMIT 1";
    res = query.store();

    if(res)
    {
        if(res.field_names()->size() == 5)
        {
            query << "ALTER TABLE `employees` ADD `photo` longblob NOT NULL AFTER `emp_comment`";
            query.execute();
            message = true;
        }
    }
    if(message)
    {
        wxMessageBox(_("Database was updated!"));
    }
}

void etmmanagerFrame::OnButton2Click1(wxCommandEvent& event)
{
    wxDateTime start_date = DatePickerCtrl1->GetValue();
    wxDateTime end_date = DatePickerCtrl2->GetValue();

    wxString htmlTable;

    htmlTable << _("Employee: ") <<  Choice1 -> GetStringSelection() << _T("<br>Start date: ") \
    << start_date.FormatDate() << _T("<br>End date: ") << end_date.FormatDate();
    htmlTable << _T("<br><br><table border=0 cellpadding=3 bgcolor=#000000><th bgcolor=white></th>");


    for(int h=0; h<6; ++h)
    {
        htmlTable << _T("<th bgcolor=white>") << Grid1->GetColLabelValue(h) << _T("</th>");
    }


    int i = 0;
    for(i; i < Grid1->GetNumberRows(); ++i)
    {
        if(Grid1->GetCellValue(i,0) == _T(""))
            break;
    }

    for(int j=0; j < i; ++j)
    {
        htmlTable << _T("<tr>");
        htmlTable << _T("<td bgcolor=white>") << Grid1->GetRowLabelValue(j) << _T("</td>");

        int cell_w;
        int cell_h;
        Grid1->GetCellSize(j,0,&cell_h,&cell_w);

        if(cell_w != 6)
        {
            for(int k=0; k < 6; ++k)
            {
                htmlTable << _T("<td bgcolor=")<< Grid1->GetCellBackgroundColour(j,k).GetAsString(wxC2S_HTML_SYNTAX) <<_T(">") << Grid1->GetCellValue(j,k) << _T("</td>");
            }
        }
        else
        {
            htmlTable << _T("<td colspan = 6 align = center bgcolor=")<< Grid1->GetCellBackgroundColour(j,0).GetAsString(wxC2S_HTML_SYNTAX) <<_T(">")<< Grid1->GetCellValue(j,0) << _T("</td>");
        }

        htmlTable << _T("</tr>");
    }

    htmlTable << _T("</table>");

    printTable(htmlTable);

}
