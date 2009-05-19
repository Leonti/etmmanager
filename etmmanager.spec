Summary: ETM Manager (part of Employee Time Management project)
Name: etmmanager
Version: 0.6.0
Release: 3
Source0: %{name}-%{version}.tar.gz
License: GPL v2
URL: http://etm.leonti.ru
Group: Utilities
BuildRoot: %{_builddir}/%{name}-root
%description
ETM Manager - software to count time and wages of employees.
Creates list of employees and list of possible jobs for every employee.
Needs MySQL server to be installed on the same machine for backup/restore from backup
features to function.
Part of ETM project.
Use with Time Logger 0.6.0 or later
%prep
%setup -q
%build
./configure
make
%install
rm -rf $RPM_BUILD_ROOT
make DESTDIR=$RPM_BUILD_ROOT install
%clean
rm -rf $RPM_BUILD_ROOT
%files
%defattr(-,root,root)
/usr/local/bin/*
/usr/local/share/etmmanager/*
%changelog
* Sat Apr 12 12:00:00 2008 Leonti Bielski <prishelec@gmail.com> 0.6.0
- First public release of ETM Manager
- Works with Time Logger 0.6.0