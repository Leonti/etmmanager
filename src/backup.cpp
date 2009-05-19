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
#include "backup.h"
#include <wx/platinfo.h>

long make_dump(wxConfigBase *confi, const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename){
wxString mysqlName = _T("mysqldump");
if(confi->Read(_T("/program/usebin"))==_T("1")){
wxFileName mysqlDirName(confi->Read(_T("/program/mysqldir")), mysqlName);
mysqlName = mysqlDirName.GetFullPath();
    }

wxPlatformInfo platInfo;
wxString systemName = platInfo.GetOperatingSystemFamilyName();

wxString command; //dirty workaround " problem
if(systemName == _T("Unix")){
command = mysqlName + _T(" --user=") + user + _T(" --password=") + password + _T(" --host=") + host + _T(" --result-file=") +filename + _T(" ") + db_name;
}else if(systemName == _T("Windows")){
command = _T("\"") + mysqlName + _T("\"") + _T(" --user=") + user + _T(" --password=") + password + _T(" --host=") + host + _T(" --result-file=") + _T("\"") +filename + _T("\"")+ _T(" ") + db_name;
    }
    long result = wxExecute(command, wxEXEC_SYNC);
    return result;
    }

long restore_table(wxConfigBase *confi, const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename){
wxString mysqlName = _T("mysql");
if(confi->Read(_T("/program/usebin"))==_T("1")){
wxFileName mysqlDirName(confi->Read(_T("/program/mysqldir")), mysqlName);
mysqlName = mysqlDirName.GetFullPath();
    }
wxPlatformInfo platInfo;
wxString systemName = platInfo.GetOperatingSystemFamilyName();

wxString command;
if(systemName == _T("Unix")){
command = mysqlName + _T(" --user=") + user + _T(" --password=") + password + _T(" --host=") + host + _T(" --database=") + db_name + _T(" < ") + filename  ;
}else if(systemName == _T("Windows")){
command =  _T("\"\"") + mysqlName + _T("\" ") + _T(" < \"") + filename  + _T("\" --user=") + user + _T(" --password=") + password + _T(" --host=") + host + _T(" --database=") + db_name + _T("\"");
    }
    long result = wxShell(command);
    return result;
    }
