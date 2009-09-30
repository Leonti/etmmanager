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
#include "contracts.h"

//(*InternalHeaders(contracts)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)
#include <wx/msgdlg.h>
//(*IdInit(contracts)
const long contracts::ID_STATICTEXT1 = wxNewId();
const long contracts::ID_LISTBOX1 = wxNewId();
const long contracts::ID_STATICTEXT2 = wxNewId();
const long contracts::ID_CHOICE1 = wxNewId();
const long contracts::ID_STATICTEXT3 = wxNewId();
const long contracts::ID_TEXTCTRL1 = wxNewId();
const long contracts::ID_STATICTEXT4 = wxNewId();
const long contracts::ID_TEXTCTRL2 = wxNewId();
const long contracts::ID_STATICTEXT5 = wxNewId();
const long contracts::ID_TEXTCTRL3 = wxNewId();
const long contracts::ID_CHECKBOX1 = wxNewId();
const long contracts::ID_BUTTON1 = wxNewId();
const long contracts::ID_BUTTON2 = wxNewId();
const long contracts::ID_BUTTON3 = wxNewId();
const long contracts::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(contracts,wxDialog)
    //(*EventTable(contracts)
    //*)
END_EVENT_TABLE()

contracts::contracts(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(contracts)
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer3;

    Create(parent, wxID_ANY, _("Overtime settings"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
    FlexGridSizer1 = new wxFlexGridSizer(4, 0, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Set and edit overtime limits settings"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(3, 2, 0, 0);
    ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(346,171), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
    FlexGridSizer2->Add(ListBox1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(5, 2, 0, 0);
    StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("New payweek starts from:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer4->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    FlexGridSizer4->Add(Choice1, 1, wxALL|wxEXPAND|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Overtime limit week hours:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer4->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(39,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Overtime limit day hours:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer4->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(39,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    FlexGridSizer4->Add(TextCtrl2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Overtime wage multiplier"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer4->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl3 = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(41,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
    FlexGridSizer4->Add(TextCtrl3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Default"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBox1->SetValue(false);
    FlexGridSizer4->Add(CheckBox1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer4, 1, wxTOP|wxBOTTOM|wxLEFT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(2, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer3->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer3->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(this, ID_BUTTON3, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(FlexGridSizer3, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2->Add(0,0,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer2->Add(Button4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&contracts::OnListBox1Select);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contracts::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contracts::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contracts::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&contracts::OnButton4Click);
    //*)
    for(int i=0; i<7; i++)
    {
        wxDateTime::WeekDay day = wxDateTime::WeekDay(i);
        Choice1->Append(wxDateTime::GetWeekDayName(day));
    }
    Choice1->SetSelection(0);
    FlexGridSizer1->SetSizeHints(this);
}

contracts::~contracts()
{
    //(*Destroy(contracts)
    //*)
}

void contracts::fillAll()
{

    mysqlpp::Query query = conn -> query();
    query << "SELECT * FROM `contracts`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            contractIds.Add(int(row["id"]));
            wxString weekLimit = std2wx(std::string(row["week_limit"]),wxConvUI);
            wxString dayLimit = std2wx(std::string(row["day_limit"]),wxConvUI);
            wxString multiplier = std2wx(std::string(row["multiplier"]),wxConvUI);
            int weekStarts = int(row["week_starts"]);
            bool isDefault = bool(row["default"]);

            wxString lstboxEntry;
            lstboxEntry << Choice1->GetString(weekStarts) << _T("; week:") << weekLimit << _T("; day:") << dayLimit << _T("; mplr:") << multiplier;
            if(isDefault)
            {
                lstboxEntry << _T(" Default");
                defContract = i;
            }

            ListBox1 -> Append(lstboxEntry);

        }
    }
}

void contracts::clearAll()
{
    ListBox1->Clear();
    Choice1->SetSelection(0);
    TextCtrl1->Clear();
    TextCtrl2->Clear();
    TextCtrl3->Clear();
    CheckBox1->SetValue(false);
    contractIds.Clear();
}

void contracts::OnButton4Click(wxCommandEvent& event)
{
    Close();
}

void contracts::OnListBox1Select(wxCommandEvent& event)
{
    mysqlpp::Query query = conn -> query();
    query << "SELECT * FROM `contracts` WHERE `id`=" << contractIds[ListBox1->GetSelection()];
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
        if(res.num_rows() !=0 )
        {
            mysqlpp::Row row = res.at(0);
            wxString weekLimit = std2wx(std::string(row["week_limit"]),wxConvUI);
            wxString dayLimit = std2wx(std::string(row["day_limit"]),wxConvUI);
            wxString multiplier = std2wx(std::string(row["multiplier"]),wxConvUI);
            int weekStarts = int(row["week_starts"]);
            bool isDefault = bool(row["default"]);

            Choice1->SetSelection(weekStarts);
            TextCtrl1->SetValue(weekLimit);
            TextCtrl2->SetValue(dayLimit);
            TextCtrl3->SetValue(multiplier);
            CheckBox1->SetValue(isDefault);
        }
    }


}

void contracts::OnButton1Click(wxCommandEvent& event)
{
    int weekStarts = Choice1 -> GetSelection();
    int Default = 0;

    mysqlpp::Query query = conn -> query();
    if(CheckBox1->GetValue())
    {
        query << "UPDATE `contracts` SET `default` = '0' WHERE `contracts`.`default` ='1'";
        query.execute();
        Default = 1;
    }

    query << "INSERT INTO `contracts`\
     (`id`, `week_starts`, `day_limit`, `week_limit`, `multiplier`, `default`)\
      VALUES (NULL, '"<< weekStarts <<"', '"<< wx2std(TextCtrl2->GetValue(), wxConvUI) <<"', '"<< wx2std(TextCtrl1->GetValue(), wxConvUI) <<"', '"<< wx2std(TextCtrl3->GetValue(), wxConvUI) <<"', '"<< Default <<"')";
    query.execute();

    clearAll();
    fillAll();

}

void contracts::OnButton3Click(wxCommandEvent& event)
{
    if(ListBox1->GetSelection() != wxNOT_FOUND)
    {
        if(ListBox1->GetSelection() != defContract)
        {
            mysqlpp::Query query = conn -> query();
            query <<"UPDATE `employees` SET `contract_id` = '0' WHERE `employees`.`contract_id` =" << contractIds[ListBox1->GetSelection()];
            query.execute();

            query << "DELETE FROM `contracts` WHERE `id`=" << contractIds[ListBox1->GetSelection()];
            query.execute();
            clearAll();
            fillAll();
        }
        else
        {
            wxMessageBox(_("You can't delete default settings! Please set another settings as default before deleting!"));
        }
    }
}

void contracts::OnButton2Click(wxCommandEvent& event)
{
    if(ListBox1->GetSelection() != wxNOT_FOUND)
    {
        int weekStarts = Choice1 -> GetSelection();
        int Default = 0;

        mysqlpp::Query query = conn -> query();
        if(CheckBox1->GetValue())
        {
            query << "UPDATE `contracts` SET `default` = '0' WHERE `contracts`.`default` ='1'";
            query.execute();
            Default = 1;
        }
        query << "UPDATE `contracts` SET `week_starts` = '"<< weekStarts <<"', \
`day_limit` = '"<< wx2std(TextCtrl2->GetValue(), wxConvUI) <<"', \
`week_limit` = '"<< wx2std(TextCtrl1->GetValue(), wxConvUI) <<"', \
`multiplier` = '"<< wx2std(TextCtrl3->GetValue(), wxConvUI) <<"', \
`default` = '"<< Default <<"' \
WHERE `contracts`.`id` = '"<< contractIds[ListBox1->GetSelection()] <<"' LIMIT 1";
        query.execute();

        clearAll();
        fillAll();
    }
}
