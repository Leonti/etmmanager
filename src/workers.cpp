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
#include "workers.h"

#include <wx/image.h>

//(*InternalHeaders(workers)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/font.h>
//*)

#include <wx/msgdlg.h>

#include <wx/filedlg.h>


//(*IdInit(workers)
const long workers::ID_STATICTEXT9 = wxNewId();
const long workers::ID_LISTBOX1 = wxNewId();
const long workers::ID_STATICTEXT1 = wxNewId();
const long workers::ID_TEXTCTRL1 = wxNewId();
const long workers::ID_STATICTEXT2 = wxNewId();
const long workers::ID_TEXTCTRL2 = wxNewId();
const long workers::ID_STATICTEXT3 = wxNewId();
const long workers::ID_TEXTCTRL3 = wxNewId();
const long workers::ID_CHOICE1 = wxNewId();
const long workers::ID_BUTTON1 = wxNewId();
const long workers::ID_BUTTON2 = wxNewId();
const long workers::ID_BUTTON3 = wxNewId();
const long workers::ID_BUTTON4 = wxNewId();
const long workers::ID_WIND1 = wxNewId();
const long workers::ID_STATICTEXT7 = wxNewId();
const long workers::ID_LISTBOX2 = wxNewId();
const long workers::ID_BUTTON5 = wxNewId();
const long workers::ID_BUTTON6 = wxNewId();
const long workers::ID_STATICTEXT8 = wxNewId();
const long workers::ID_STATICTEXT4 = wxNewId();
const long workers::ID_TEXTCTRL4 = wxNewId();
const long workers::ID_STATICTEXT5 = wxNewId();
const long workers::ID_TEXTCTRL5 = wxNewId();
const long workers::ID_STATICTEXT6 = wxNewId();
const long workers::ID_TEXTCTRL6 = wxNewId();
const long workers::ID_BUTTON7 = wxNewId();
const long workers::ID_BUTTON8 = wxNewId();
const long workers::ID_BUTTON9 = wxNewId();
const long workers::ID_LISTBOX3 = wxNewId();
const long workers::ID_BUTTON10 = wxNewId();
//*)

BEGIN_EVENT_TABLE(workers,wxDialog)
	//(*EventTable(workers)
	//*)
END_EVENT_TABLE()

workers::workers(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(workers)
	wxFlexGridSizer* FlexGridSizer8;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer11;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer9;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer10;
	wxFlexGridSizer* FlexGridSizer5;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, wxID_ANY, _("Employees and jobs editing"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	FlexGridSizer2 = new wxFlexGridSizer(4, 1, 0, 0);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Employees"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	wxFont StaticText9Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText9->SetFont(StaticText9Font);
	FlexGridSizer2->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
	ListBox1 = new wxListBox(this, ID_LISTBOX1, wxDefaultPosition, wxSize(174,390), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX1"));
	FlexGridSizer4->Add(ListBox1, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	FlexGridSizer9 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer5 = new wxFlexGridSizer(5, 2, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Name:"), wxPoint(192,40), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer5->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	w_name_txt = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxPoint(240,32), wxSize(143,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	FlexGridSizer5->Add(w_name_txt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Code:"), wxPoint(192,64), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	FlexGridSizer5->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	w_code_txt = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxPoint(240,64), wxSize(40,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	w_code_txt->SetMaxLength(4);
	w_code_txt->SetToolTip(_("Only numeric values (4 digits) are alowed"));
	FlexGridSizer5->Add(w_code_txt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Comment:"), wxPoint(176,104), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	FlexGridSizer5->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	w_comment_txt = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxPoint(248,104), wxSize(143,106), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	FlexGridSizer5->Add(w_comment_txt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(FlexGridSizer5, 1, wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Overtime settings"));
	FlexGridSizer8 = new wxFlexGridSizer(2, 1, 0, 0);
	Choice1 = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxSize(267,27), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	FlexGridSizer8->Add(Choice1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button1 = new wxButton(this, ID_BUTTON1, _("Edit"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	FlexGridSizer8->Add(Button1, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer8, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10 = new wxFlexGridSizer(2, 2, 0, 0);
	Button2 = new wxButton(this, ID_BUTTON2, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	Button2->SetToolTip(_("Add new employee to the list"));
	FlexGridSizer10->Add(Button2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("Change"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	Button3->SetToolTip(_("Change employee info"));
	FlexGridSizer10->Add(Button3, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer10->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button4 = new wxButton(this, ID_BUTTON4, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
	Button4->SetToolTip(_("Delete selected employee from the list"));
	FlexGridSizer10->Add(Button4, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer9->Add(FlexGridSizer10, 1, wxTOP|wxBOTTOM|wxLEFT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4->Add(FlexGridSizer9, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer11 = new wxFlexGridSizer(0, 2, 0, 0);
	Image1 = new wxWindow(this,ID_WIND1);
	Image1 -> SetSize(200,200);
	FlexGridSizer11->Add(Image1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(2, 2, 0, 0);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Employee\'s list of jobs:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	FlexGridSizer6->Add(StaticText7, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	worker_jobs_listbox = new wxListBox(this, ID_LISTBOX2, wxDefaultPosition, wxSize(120,176), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX2"));
	FlexGridSizer6->Add(worker_jobs_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	remove_job = new wxButton(this, ID_BUTTON5, _("Remove"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
	remove_job->Disable();
	remove_job->SetToolTip(_("Remove selected job from the list of jobs assigned to an employee"));
	FlexGridSizer6->Add(remove_job, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer11->Add(FlexGridSizer6, 1, wxLEFT|wxRIGHT|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 10);
	FlexGridSizer2->Add(FlexGridSizer11, 1, wxEXPAND|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	add_job_emp_button = new wxButton(this, ID_BUTTON6, _("<--"), wxPoint(400,344), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
	add_job_emp_button->Disable();
	add_job_emp_button->SetToolTip(_("Press this button to assign a job to an employee"));
	FlexGridSizer1->Add(add_job_emp_button, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(2, 1, 0, 0);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Jobs"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	wxFont StaticText8Font(16,wxSWISS,wxFONTSTYLE_NORMAL,wxNORMAL,false,_T("Sans"),wxFONTENCODING_DEFAULT);
	StaticText8->SetFont(StaticText8Font);
	FlexGridSizer7->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(10, 2, 0, 0);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Job title:"), wxPoint(656,200), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	j_name_txt = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxPoint(712,192), wxSize(143,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	FlexGridSizer3->Add(j_name_txt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Wage:"), wxPoint(656,232), wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	j_wage_txt = new wxTextCtrl(this, ID_TEXTCTRL5, _("0"), wxPoint(720,224), wxSize(44,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	j_wage_txt->SetToolTip(_("Enter job wage here"));
	FlexGridSizer3->Add(j_wage_txt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Comment:"), wxPoint(648,256), wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer3->Add(StaticText6, 1, wxALL|wxALIGN_LEFT|wxALIGN_TOP, 5);
	j_comment_txt = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxPoint(720,256), wxSize(143,106), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	FlexGridSizer3->Add(j_comment_txt, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
	add_job = new wxButton(this, ID_BUTTON7, _("Add"), wxPoint(664,376), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON7"));
	add_job->SetToolTip(_("Add new job to the list"));
	FlexGridSizer3->Add(add_job, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	change_job = new wxButton(this, ID_BUTTON8, _("Change"), wxPoint(760,376), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON8"));
	change_job->SetToolTip(_("Change job info"));
	FlexGridSizer3->Add(change_job, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	delete_job = new wxButton(this, ID_BUTTON9, _("Delete"), wxPoint(760,408), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON9"));
	delete_job->SetToolTip(_("Delete a job from the list"));
	FlexGridSizer3->Add(delete_job, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	jobs_listbox = new wxListBox(this, ID_LISTBOX3, wxDefaultPosition, wxSize(120,355), 0, 0, 0, wxDefaultValidator, _T("ID_LISTBOX3"));
	FlexGridSizer3->Add(jobs_listbox, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button5 = new wxButton(this, ID_BUTTON10, _("Close"), wxPoint(728,464), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON10"));
	Button5->SetToolTip(_("Close this window"));
	FlexGridSizer3->Add(Button5, 1, wxALL|wxALIGN_RIGHT|wxALIGN_BOTTOM, 5);
	FlexGridSizer7->Add(FlexGridSizer3, 1, wxTOP|wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(FlexGridSizer7, 1, wxALL|wxALIGN_TOP|wxALIGN_CENTER_HORIZONTAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_LISTBOX1,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&workers::OnListBox1Select);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton1Click1);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton1Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton2Click);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton3Click);
	Image1->Connect(wxEVT_PAINT,(wxObjectEventFunction)&workers::OnImage1Paint,0,this);
	Image1->Connect(wxEVT_LEFT_UP,(wxObjectEventFunction)&workers::OnImage1LeftUp,0,this);
	Connect(ID_LISTBOX2,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&workers::Onworker_jobs_listboxSelect);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::Onremove_jobClick);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::Onadd_job_emp_buttonClick);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::Onadd_jobClick);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::Onchange_jobClick);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::Ondelete_jobClick);
	Connect(ID_LISTBOX3,wxEVT_COMMAND_LISTBOX_SELECTED,(wxObjectEventFunction)&workers::Onjobs_listboxSelect);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&workers::OnButton4Click);
	//*)


//		Image1 -> SetSize(200,200); //paste above
}

workers::~workers()
{
	//(*Destroy(workers)
	//*)
}
void workers::fill_all(){
    refresh_workers();
    refresh_jobs();
    refreshLimits();
    }
void workers::refresh_workers(){
    ListBox1 -> Clear();
    workers_ids.Clear();
    mysqlpp::Query query = conn_workers -> query();
    query << "SELECT * FROM `employees`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
            std::string work_name = std::string(row["emp_name"]);
            ListBox1->Append(std2wx(work_name, wxConvUI));
            workers_ids.Add(int(row["emp_id"]));
        }
    }

       add_job_emp_button->Enable(false);
       remove_job->Enable(false);
       worker_jobs_listbox->Clear();
    }

 void workers::refresh_jobs(){
    jobs_listbox -> Clear();
    jobs_ids.Clear();
    mysqlpp::Query query = conn_workers -> query();
    query << "SELECT * FROM `jobs`";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
            jobs_listbox->Append(std2wx(std::string(row["job_title"]), wxConvUI));
            jobs_ids.Add(int(row["job_id"]));
        }
    }

add_job_emp_button->Enable(false);
     }

void workers::work_txt_clear(){
    w_name_txt -> Clear();
    w_code_txt -> Clear();
    w_comment_txt -> Clear();
    }
void workers::job_txt_clear(){
    j_name_txt -> Clear();
    j_wage_txt -> SetValue(_T("0"));
    j_comment_txt -> Clear();
    }

void workers::OnButton4Click(wxCommandEvent& event)
{
    Show(0);
}

void workers::OnButton3Click(wxCommandEvent& event)
{
       if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_workers -> query();
        query << "DELETE FROM `employees` WHERE `employees`.`emp_id` = "<< workers_ids[ListBox1 -> GetSelection()] <<" LIMIT 1";
        query.execute();
        query << "DELETE FROM `emp_jobs` WHERE `emp_id` = "<< workers_ids[ListBox1 -> GetSelection()];
        query.execute();
        refresh_workers();
        work_txt_clear();
    }
}

void workers::OnButton1Click(wxCommandEvent& event)
{
          if (!w_name_txt->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<ListBox1->GetCount(); i++)
        {
            if (w_name_txt->GetValue() == ListBox1->GetString(i))
            {
                wxMessageBox(_("This worker already exists."));
                exist = 1;
                i=ListBox1->GetCount();
            }
        }
        if (exist == 0)
        {
            int contractId = 0;
            if(Choice1->GetSelection() != contractDef){
                contractId = contractIds[Choice1->GetSelection()];
                }
            mysqlpp::Query query = conn_workers -> query();
            query << "INSERT INTO `employees` (`emp_id`, `emp_name`, `emp_ssn`, `emp_comment`, `contract_id`) VALUES (NULL, '"<< wx2std(w_name_txt->GetValue(), wxConvUI) <<"', '"<< wx2std(w_code_txt->GetValue(), wxConvUI) <<"', '"<< wx2std(w_comment_txt->GetValue(), wxConvUI) <<"', '"<< contractId <<"')";
            query.execute();
            refresh_workers();
            work_txt_clear();
        }


    }

refreshLimits();
}

void workers::OnButton2Click(wxCommandEvent& event)
{
        if (ListBox1->GetSelection() != wxNOT_FOUND){


            if (!w_name_txt->IsEmpty())
    {
            int contractId = 0;

            if(Choice1->GetSelection() != contractDef){
                contractId = contractIds[Choice1->GetSelection()];
//            wxString tmp;
//            tmp << contractId << _(" default: ") << contractDef;
//            wxMessageBox(tmp);
                }
        mysqlpp::Query query = conn_workers -> query();
        query << "UPDATE `employees` SET `emp_name` = '"<<wx2std(w_name_txt->GetValue(), wxConvUI)<< "', `emp_ssn` = '"<<wx2std(w_code_txt->GetValue(), wxConvUI)<< "', `emp_comment` = '"<<wx2std(w_comment_txt->GetValue(), wxConvUI)<< "', `contract_id` = '"<< contractId <<"' WHERE `employees`.`emp_id` = "<< workers_ids[ListBox1 -> GetSelection()] <<" LIMIT 1;";
        query.execute();


        refresh_workers();
        work_txt_clear();

    }
        }
        refreshLimits();
}

void workers::OnListBox1Select(wxCommandEvent& event)
{
        if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_workers->query();
        query << "SELECT * FROM `employees` WHERE `emp_id`=" << workers_ids[ListBox1 -> GetSelection()] << " LIMIT 1";
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            mysqlpp::Row row = res.at(0);
            work_txt_clear();
            w_name_txt -> ChangeValue(std2wx(std::string(row["emp_name"]),wxConvUI));
            w_code_txt -> ChangeValue(std2wx(std::string(row["emp_ssn"]),wxConvUI));
            w_comment_txt -> ChangeValue(std2wx(std::string(row["emp_comment"]),wxConvUI));
            int contractId = int(row["contract_id"]);
            if(contractId != 0){
            Choice1 -> SetSelection(contractIds.Index(contractId));
                }else{
            Choice1 -> SetSelection(contractDef);
                    }

    wxPoint p=photoWindow->GetPosition();
    wxSize sz=photoWindow->GetClientSize();

mysqlpp::Row::reference it = row["photo"];
int length = it.length();
                    if(length != 0){
const char* str = it.data();

unsigned char * NewImgData = ( unsigned char * ) malloc( length );

    memcpy( NewImgData, str, length );
    wxImage img(200,200,NewImgData);
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);
}else{
wxStandardPaths path;
wxFileName imageName;
imageName.Assign(path.GetDataDir(),_T("photo.png"));

    wxImage img(imageName.GetFullPath(),wxBITMAP_TYPE_PNG);
    photoDC -> Clear();
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);
    photoDC -> DrawText(_("No photo"), 10, 10);
}
        }

if (jobs_listbox->GetSelection() != wxNOT_FOUND){
    add_job_emp_button->Enable(true);
    }
refresh_work_jobs();
    }
}

void workers::Onjobs_listboxSelect(wxCommandEvent& event)
{
           if (jobs_listbox->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_workers->query();
        query << "SELECT * FROM `jobs` WHERE `job_id`=" << jobs_ids[jobs_listbox -> GetSelection()] << " LIMIT 1";
        mysqlpp::StoreQueryResult res = query.store();

        if (res)
        {
            mysqlpp::Row row = res.at(0);
            job_txt_clear();
            j_name_txt -> ChangeValue(std2wx(std::string(row["job_title"]),wxConvUI));
            j_wage_txt -> ChangeValue(std2wx(std::string(row["job_wage"]),wxConvUI));
            j_comment_txt -> ChangeValue(std2wx(std::string(row["job_description"]),wxConvUI));
        }

if (ListBox1->GetSelection() != wxNOT_FOUND){
    add_job_emp_button->Enable(true);
    }
    }
}

void workers::Onadd_jobClick(wxCommandEvent& event)
{
              if (!j_name_txt->IsEmpty())
    {
        int exist=0;
        for (unsigned int i = 0; i<jobs_listbox->GetCount(); i++)
        {
            if (j_name_txt->GetValue() == jobs_listbox->GetString(i))
            {
                wxMessageBox(_("This job already exists."));
                exist = 1;
                i=jobs_listbox->GetCount();
            }
        }
        if (exist == 0)
        {

            mysqlpp::Query query = conn_workers -> query();
            query << "INSERT INTO `jobs` (`job_id`, `job_title`, `job_wage`, `job_description`) VALUES (NULL, '"<< wx2std(j_name_txt->GetValue(), wxConvUI) <<"', '"<< wx2std(j_wage_txt->GetValue(), wxConvUI) <<"', '"<< wx2std(j_comment_txt->GetValue(), wxConvUI) <<"')";
            query.execute();
            refresh_jobs();
            job_txt_clear();
        }


    }

}

void workers::Onchange_jobClick(wxCommandEvent& event)
{
            if (jobs_listbox->GetSelection() != wxNOT_FOUND){


            if (!j_name_txt->IsEmpty())
    {

        mysqlpp::Query query = conn_workers -> query();
//        query << "UPDATE `employees` SET `emp_name` = '"<<wx2std(w_name_txt->GetValue(), wxConvUI)<< "', `emp_ssn` = '"<<wx2std(w_code_txt->GetValue(), wxConvUI)<< "', `emp_comment` = '"<<wx2std(w_comment_txt->GetValue(), wxConvUI)<< "' WHERE `employees`.`emp_id` = "<< workers_ids[ListBox1 -> GetSelection()] <<" LIMIT 1;";
        query << "UPDATE `jobs` SET `job_title` = '"<<wx2std(j_name_txt->GetValue(), wxConvUI)<< "', `job_wage` = '"<<wx2std(j_wage_txt->GetValue(), wxConvUI)<< "', `job_description` = '"<<wx2std(j_comment_txt->GetValue(), wxConvUI)<< "' WHERE `jobs`.`job_id` ="<< jobs_ids[jobs_listbox -> GetSelection()] <<" LIMIT 1";
        query.execute();


        refresh_jobs();
        job_txt_clear();

    }
        }
}

void workers::Ondelete_jobClick(wxCommandEvent& event)
{
           if (jobs_listbox->GetSelection() != wxNOT_FOUND)
    {
        mysqlpp::Query query = conn_workers -> query();
        query << "DELETE FROM `jobs` WHERE `jobs`.`job_id` = "<< jobs_ids[jobs_listbox -> GetSelection()] <<" LIMIT 1";
        query.execute();
        query << "DELETE FROM `emp_jobs` WHERE `job_id` = "<< jobs_ids[jobs_listbox -> GetSelection()];
        query.execute();
        refresh_jobs();
        job_txt_clear();
    }
}

void workers::Onadd_job_emp_buttonClick(wxCommandEvent& event)
{
    //INSERT INTO `emp_jobs` (`id`, `emp_id`, `job_id`) VALUES (NULL, '3', '2')
        mysqlpp::Query query = conn_workers -> query();
        query << "INSERT INTO `emp_jobs` (`id`, `emp_id`, `job_id`) VALUES (NULL, '"<< workers_ids[ListBox1 -> GetSelection()] <<"', '"<< jobs_ids[jobs_listbox -> GetSelection()] <<"')";
        query.execute();
refresh_work_jobs();
}
void workers::refresh_work_jobs(){
    worker_jobs_listbox->Clear();
    work_job_ids.Clear();
    mysqlpp::Query query = conn_workers -> query();
    query << "SELECT * FROM `emp_jobs` WHERE `emp_id` ='"<< workers_ids[ListBox1 -> GetSelection()] <<"'";
    mysqlpp::StoreQueryResult res = query.store();
    if (res)
    {
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
  row = res[i];
            int job_id = int(row["job_id"]);
            query << "SELECT `job_title` FROM `jobs` WHERE `job_id`='"<< job_id <<"' LIMIT 1";
            mysqlpp::StoreQueryResult res2 = query.store();
            mysqlpp::Row row2 = res2.at(0);
            worker_jobs_listbox->Append(std2wx(std::string(row2["job_title"]), wxConvUI));
            work_job_ids.Add(int(row["id"]));
        }
    }

    remove_job->Enable(false);

    }

void workers::Onworker_jobs_listboxSelect(wxCommandEvent& event)
{
        remove_job->Enable(true);
}

void workers::Onremove_jobClick(wxCommandEvent& event)
{
        mysqlpp::Query query = conn_workers -> query();
        query << "DELETE FROM `emp_jobs` WHERE `id` = "<< work_job_ids[worker_jobs_listbox -> GetSelection()] <<" LIMIT 1";
        query.execute();
        refresh_work_jobs();
}

void workers::refreshLimits(){
Choice1 -> Clear();
contractIds.Clear();
    mysqlpp::Query query = conn_workers -> query();
    query << "SELECT * FROM `contracts`";
    mysqlpp::StoreQueryResult res = query.store();
   if (res)
    {
        int defaultPosition = 0;
mysqlpp::Row row;
mysqlpp::StoreQueryResult::size_type i;
for (i = 0; i < res.num_rows(); ++i) {
      row = res[i];

contractIds.Add(int(row["id"]));
wxString weekLimit = std2wx(std::string(row["week_limit"]),wxConvUI);
wxString dayLimit = std2wx(std::string(row["day_limit"]),wxConvUI);
wxString multiplier = std2wx(std::string(row["multiplier"]),wxConvUI);
int weekStarts = int(row["week_starts"]);
bool isDefault = bool(row["default"]);


    wxDateTime::WeekDay day = wxDateTime::WeekDay(weekStarts);

wxString lstboxEntry;
lstboxEntry << wxDateTime::GetWeekDayName(day) << _T("; week:") << weekLimit << _T("; day:") << dayLimit << _T("; mplr:") << multiplier;
if(isDefault){
    lstboxEntry << _T(" Default");
    defaultPosition = i;
    contractDef = i;
    }

Choice1 -> Append(lstboxEntry);
Choice1 -> SetSelection(defaultPosition);
    }
    }

    }

void workers::OnButton1Click1(wxCommandEvent& event)
{
    contracts* limitsDlg = new contracts(this);
    limitsDlg->conn = conn_workers;
    limitsDlg->fillAll();
    limitsDlg->ShowModal();
    refreshLimits();
}

void workers::OnImage1Paint(wxPaintEvent& event)
{
    wxStandardPaths path;
wxFileName imageName;
imageName.Assign(path.GetDataDir(),_T("photo.png"));
        wxImage img(imageName.GetFullPath(),wxBITMAP_TYPE_PNG);
    photoWindow = FindWindow(ID_WIND1);
    photoDC = new wxClientDC(photoWindow);

    wxPoint p=photoWindow->GetPosition();
    wxSize sz=photoWindow->GetClientSize();
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);
//  evt.Skip();
}

void workers::OnImage1LeftUp(wxMouseEvent& event)
{


    //saving image to the database
            if (ListBox1->GetSelection() != wxNOT_FOUND)
    {
    wxFileDialog* filedialog = new wxFileDialog(this);
    filedialog -> SetWildcard(_T("JPG files (*.jpg)|*.jpg|GIF files (*.gif)|*.gif"));
    filedialog -> ShowModal();

    if(filedialog->GetFilename() != _T("")){
    wxImage img(filedialog->GetPath(), wxBITMAP_TYPE_ANY);
    wxPoint p=photoWindow->GetPosition();
    wxSize sz=photoWindow->GetClientSize();
    photoDC -> DrawBitmap(img.Scale(sz.GetWidth(),sz.GetHeight()),0,0,false);

        std::ostringstream os;
        img.Rescale(200,200);
int dataSize = img.GetWidth( )*img.GetHeight( )*3;

os.write((char *) (img.GetData()), dataSize);

std::string histStr = os.str();
//wxMessageBox(std2wx(histStr,wxConvUI));



        mysqlpp::Query query = conn_workers->query();
        query << "UPDATE `employees` SET `photo` = '" << mysqlpp::escape << histStr << "' WHERE `emp_id`=" << workers_ids[ListBox1 -> GetSelection()] << " LIMIT 1";
        query.execute();

    }
    //end saving



    }

}
