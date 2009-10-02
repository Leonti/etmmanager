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
#include "edit_time.h"

//(*InternalHeaders(edit_time)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(edit_time)
const long edit_time::ID_STATICTEXT1 = wxNewId();
const long edit_time::ID_GRID1 = wxNewId();
const long edit_time::ID_BUTTON1 = wxNewId();
const long edit_time::ID_BUTTON2 = wxNewId();
const long edit_time::ID_BUTTON3 = wxNewId();
const long edit_time::ID_BUTTON4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(edit_time,wxDialog)
    //(*EventTable(edit_time)
    //*)
END_EVENT_TABLE()

edit_time::edit_time(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    //(*Initialize(edit_time)
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;

    Create(parent, id, _("Edit time entries"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
    SetClientSize(wxDefaultSize);
    Move(wxDefaultPosition);
    FlexGridSizer1 = new wxFlexGridSizer(4, 1, 0, 0);
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
    Grid1->CreateGrid(2,2);
    Grid1->EnableEditing(true);
    Grid1->EnableGridLines(true);
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    FlexGridSizer1->Add(Grid1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    Button1 = new wxButton(this, ID_BUTTON1, _("Add"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    FlexGridSizer2->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(this, ID_BUTTON2, _("Delete"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    FlexGridSizer2->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    Button3 = new wxButton(this, ID_BUTTON3, _("Save"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    FlexGridSizer3->Add(Button3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(this, ID_BUTTON4, _("Cancel"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    FlexGridSizer3->Add(Button4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(this);
    FlexGridSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&edit_time::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&edit_time::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&edit_time::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&edit_time::OnButton4Click);
    //*)
    Grid1->SetRowLabelValue(0,_T(""));
    Grid1->SetRowLabelValue(1,_T(""));
    Grid1->SetColLabelValue(0,_("Time"));
    Grid1->SetColLabelValue(1,_("Job"));

    Grid1->SetColSize(1,130);

}

edit_time::~edit_time()
{
    //(*Destroy(edit_time)
    //*)
}
void edit_time::fill_all(wxString& date, int emp_id)
{
    employee_id = emp_id;
    today.ParseDate(date.c_str());
    StaticText1->SetLabel(today.FormatDate());

    wxDateTime mysql_date = today;
    mysql_date.Add(wxTimeSpan::Day());

    mysqlpp::Query query = conn->query();
    query << "SELECT * FROM `time` WHERE `time_time` > '"<< wx2std(today.FormatISODate(),wxConvUI) <<"' AND `time_time` < '"<< wx2std(mysql_date.FormatISODate(),wxConvUI) <<"' AND `time_emp_id` = '"<< emp_id <<"' ORDER BY `time_time` ASC";
    mysqlpp::StoreQueryResult res = query.store();

    query << "SELECT `job_id`,`job_title` FROM `jobs`";
    mysqlpp::StoreQueryResult res_job = query.store();

    times.Add(_T(""), 2);
    job_names.Add(_T(""), 2);
    time_ids.Add(0, 2);

    if(res_job)
    {
        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res_job.num_rows(); ++i)
        {
            row = res_job[i];
            jobs.Add(std2wx(std::string(row["job_title"]),wxConvUI));
            job_ids.Add(int(row["job_id"]));
        }
        jobs.Add(_("OFF"));
        job_ids.Add(0);
    }

    Grid1->SetCellValue(0,1,jobs[0]);
    job_names[0] = jobs[0];
    Grid1->SetCellEditor(0,1,new wxGridCellChoiceEditor(jobs));
    Grid1->SetCellValue(1,1,jobs[jobs.GetCount()-1]);
    job_names[1] = jobs[jobs.GetCount()-1];
    Grid1->SetCellEditor(1,1,new wxGridCellChoiceEditor(jobs));


    if(res)
    {
        int num = res.num_rows();
        if(num > 2)
        {
            Grid1->AppendRows(num - 2);
            times.Add(_T(""),num-2);
            job_names.Add(_T(""),num-2);
            time_ids.Add(0, num-2);
        }
        for(int j = 0; j < num; j++)
        {
            Grid1->SetRowLabelValue(j,_T(""));
        }



        mysqlpp::Row row;
        mysqlpp::StoreQueryResult::size_type i;
        for (i = 0; i < res.num_rows(); ++i)
        {
            row = res[i];
            wxDateTime timec;
            timec.ParseDateTime(std2wx(std::string(row["time_time"]),wxConvUI).c_str());
            wxString timec_str = timec.FormatTime();
            int job_id = int(row["time_job_id"]);

            time_ids[i] = int(row["time_id"]);

            int jj;
            for(jj = 0; jj < job_ids.GetCount(); jj++)
            {
                if(job_ids[jj] == job_id) break;
            }

            Grid1->SetCellValue(i,0,timec_str);
            times[i] = timec_str;
            Grid1->SetCellValue(i,1,jobs[jj]);
            job_names[i]=jobs[jj];
            Grid1->SetCellEditor(i,1,new wxGridCellChoiceEditor(jobs));

        }

        if(num !=0) Grid1->AutoSizeColumn(0);
        FlexGridSizer1->SetSizeHints(this);
    }


}

void edit_time::OnButton4Click(wxCommandEvent& event)
{
    Show(0);
}

void edit_time::OnButton1Click(wxCommandEvent& event)
{
    Grid1->AppendRows(1);
    times.Add(_T(""));
    job_names.Add(_T(""));
    time_ids.Add(0);
    Grid1->SetCellValue(Grid1->GetRows()-1,1,jobs[0]);
    Grid1->SetCellEditor(Grid1->GetRows()-1,1,new wxGridCellChoiceEditor(jobs));
    Grid1->SetRowLabelValue(Grid1->GetRows()-1,_T(""));
    FlexGridSizer1->SetSizeHints(this);
}

void edit_time::OnButton2Click(wxCommandEvent& event)
{
    wxArrayInt selection = Grid1->GetSelectedRows();
    for(int i = selection.GetCount()-1; i>=0; i--)
    {
        Grid1->DeleteRows(selection[i],1);
        times.RemoveAt(selection[i],1);
        job_names.RemoveAt(selection[i],1);
        to_delete.Add(time_ids[selection[i]]);
        time_ids.RemoveAt(selection[i],1);

    }
    FlexGridSizer1->SetSizeHints(this);
}

void edit_time::OnButton3Click(wxCommandEvent& event)
{
    mysqlpp::Query query = conn->query();
    for(int i=0; i<times.GetCount(); i++)
    {

        if(Grid1->GetCellValue(i,0) != times[i] || Grid1->GetCellValue(i,1) != job_names[i])
        {
            wxDateTime to_write;
            to_write = today;
            to_write.ParseTime(Grid1->GetCellValue(i,0).c_str());
            wxString to_write_str = to_write.FormatISODate() + _T(" ") + to_write.FormatISOTime();

            int jj;
            for(jj = 0; jj < jobs.GetCount(); jj++)
            {
                if(jobs[jj] == Grid1->GetCellValue(i,1)) break;
            }
            int job_id_wr = job_ids[jj];





            if(time_ids[i] !=0 )
            {
                //editing old entry
                query << "UPDATE `time` SET `time_emp_id` = '"<< employee_id <<"', `time_time` = '"<< wx2std(to_write_str, wxConvUI) <<"', `time_job_id` = '"<< job_id_wr <<"', `time_edited` = '1' WHERE `time`.`time_id` = "<< time_ids[i] <<" LIMIT 1";
                query.execute();
            }
            else
            {
                //adding new entry
                query << "INSERT INTO `time` (`time_id`, `time_emp_id`, `time_time`, `time_job_id`, `time_edited`) VALUES (NULL, '"<< employee_id <<"', '"<< wx2std(to_write_str, wxConvUI) <<"', '"<< job_id_wr <<"', '1')";
                query.execute();
            }

        }
    }

    for(int i=0; i<to_delete.GetCount(); i++)
    {
        wxString prov;
        if(to_delete[i]!=0)
        {
            query << "DELETE FROM `time` WHERE `time`.`time_id` = "<< to_delete[i] <<" LIMIT 1";
            query.execute();
        }
    }
    Show(0);
}
