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
#include "prog_set_panel_adv.h"
//(*InternalHeaders(prog_set_panel_adv)
#include <wx/string.h>
#include <wx/intl.h>
//*)
#include <wx/msgdlg.h>

//(*IdInit(prog_set_panel_adv)
const long prog_set_panel_adv::ID_CHECKBOX1 = wxNewId();
const long prog_set_panel_adv::ID_STATICTEXT1 = wxNewId();
const long prog_set_panel_adv::ID_CUSTOM1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(prog_set_panel_adv,wxPanel)
	//(*EventTable(prog_set_panel_adv)
	//*)
END_EVENT_TABLE()

prog_set_panel_adv::prog_set_panel_adv(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(prog_set_panel_adv)
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxStaticBoxSizer* StaticBoxSizer1;

	Create(parent, id, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("id"));
	FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("File pathes:"));
	FlexGridSizer2 = new wxFlexGridSizer(3, 0, 0, 0);
	CheckBox1 = new wxCheckBox(this, ID_CHECKBOX1, _("Use own path to Mysql bin directory"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckBox1->SetValue(false);
	FlexGridSizer2->Add(CheckBox1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("MySQL bin directory path:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DirPickerCtrl1 = new wxDirPickerCtrl(this,ID_CUSTOM1,wxEmptyString,_("Select a folder"),wxDefaultPosition,wxDefaultSize,wxDIRP_DEFAULT_STYLE,wxDefaultValidator,_T("ID_CUSTOM1"));
	FlexGridSizer3->Add(DirPickerCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->Fit(this);
	FlexGridSizer1->SetSizeHints(this);

	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&prog_set_panel_adv::OnCheckBox1Click);
	//*)
	DirPickerCtrl1->Enable(false);
}

prog_set_panel_adv::~prog_set_panel_adv()
{
	//(*Destroy(prog_set_panel_adv)
	//*)
}
void prog_set_panel_adv::fill_all(){
    if(set_now->useBin){
    DirPickerCtrl1->SetPath(set_now->mysqlBin);
    }
if(confi->Read(_T("/program/usebin"))==_T("1")){
    CheckBox1->SetValue(true);
    DirPickerCtrl1->Enable(true);
    }
    }
void prog_set_panel_adv::Save(){
    confi->Write(_T("/program/mysqldir"),DirPickerCtrl1->GetPath());
 //   wxMessageBox(DirPickerCtrl1->GetPath());
    if(set_now->useBin)
    confi->Write(_T("/program/usebin"),_T("1"));
    else
    confi->Write(_T("/program/usebin"),_T("0"));
        }


void prog_set_panel_adv::OnCheckBox1Click(wxCommandEvent& event)
{
    if(CheckBox1->GetValue()){
        set_now->useBin = true;
    DirPickerCtrl1->Enable(true);
        }else{
        set_now->useBin = false;
    DirPickerCtrl1->Enable(false);
                        }
}
