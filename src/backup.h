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
#ifndef BACKUP_H
#define BACKUP_H
#include <wx/msgdlg.h>
#include <wx/utils.h>
#include <wx/string.h>
#include <wx/ffile.h>
#include <mysql++.h>
#include <wx/regex.h>
#include <wx/tokenzr.h>

#include <string>
#include <iostream>
#include <sstream>


#include <wx/stdpaths.h>

long make_dump(const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename);
long restore_table(const wxString& host,const  wxString& user, const wxString& password, const wxString& db_name, const wxString& filename);
int makeDump(mysqlpp::Connection*, const wxString& filename);
int restoreFromDump(mysqlpp::Connection*, const wxString& filename);
std::string string2hexString(const char* data, const int datasize);

//std::string char_to_hex( const char* _pArray, int _len );
#endif