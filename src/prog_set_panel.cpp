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
#include "prog_set_panel.h"

//(*InternalHeaders(prog_set_panel)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//(*IdInit(prog_set_panel)
const long prog_set_panel::ID_STATICTEXT6 = wxNewId();
const long prog_set_panel::ID_CHOICE2 = wxNewId();
const long prog_set_panel::ID_STATICTEXT5 = wxNewId();
//*)

BEGIN_EVENT_TABLE(prog_set_panel,wxPanel)
	//(*EventTable(prog_set_panel)
	//*)
END_EVENT_TABLE()

prog_set_panel::prog_set_panel(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(prog_set_panel)
	wxStaticBoxSizer* StaticBoxSizer2;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer4;

	Create(parent, id, wxDefaultPosition, wxSize(290,229), wxTAB_TRAVERSAL, _T("id"));
	FlexGridSizer1 = new wxFlexGridSizer(3, 0, 0, 0);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Appearance"));
	FlexGridSizer2 = new wxFlexGridSizer(2, 1, 0, 0);
	FlexGridSizer4 = new wxFlexGridSizer(0, 3, 0, 0);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Language:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	FlexGridSizer4->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Choice2 = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	Choice2->SetSelection( Choice2->Append(_("English")) );
	Choice2->Append(_("Spanish"));
	Choice2->Append(_("Polish"));
	Choice2->Append(_("Russian"));
	Choice2->Append(_("Portuguese"));
	FlexGridSizer4->Add(Choice2, 1, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("You need to restart program for language \nsettings to take effect!"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer2->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(StaticBoxSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	FlexGridSizer1->SetSizeHints(this);
	//*)
	langs.Add(0); //for english
	langs.Add(wxLANGUAGE_SPANISH);
	langs.Add(wxLANGUAGE_POLISH);
	langs.Add(wxLANGUAGE_RUSSIAN);
	langs.Add(wxLANGUAGE_PORTUGUESE);
}

prog_set_panel::~prog_set_panel()
{
	//(*Destroy(prog_set_panel)
	//*)
}

void prog_set_panel::fill_all(){
if(set_now->lang == 0){
    }else{
for(int i=0; i<langs.GetCount(); ++ i){
    if(set_now->lang == langs[i]){
    Choice2->SetSelection(i);
    break;
        }
    }
        }
    }



void prog_set_panel::Save(){
wxString temp;
temp << langs[Choice2->GetSelection()];
confi->Write(_T("/program/lang"),temp);
set_now->lang = langs[Choice2->GetSelection()];
    }


