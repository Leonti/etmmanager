Name:           etmmanager-0.7.0
# List of additional build dependencies
#BuildRequires:  gcc-c++ libxml2-devel
BuildRequires: gcc-c++ wxGTK-devel libmysqlpp3-devel
Version:        0.7.0
Release:        1
License:        GPL v2 or later
Source:         etmmanager-0.7.0.tar.bz2
Group:          Productivity/Other
Summary:        ETM Manager

BuildRoot:      %{_tmppath}/%{name}-%{version}-build

%description
Manager for ETM (Employee Time Management) project


%prep
%setup -q -n etmmanager-%version

%build

# Assume that the package is built by plain 'make' if there's no ./configure.
# This test is there only because the wizard doesn't know much about the
# package, feel free to clean it up
if test -x ./configure; then
	%configure
fi
make

    

%install

make DESTDIR=%buildroot install



# Write a proper %%files section and remove these two commands and
# the '-f filelist' option to %%files
echo '%%defattr(-,root,root)' >filelist
find %buildroot -type f -printf '/%%P*\n' >>filelist


%clean
rm -rf %buildroot

%files -f filelist
%defattr(-,root,root)

%dir /usr/share/etmmanager

# This is a place for a proper filelist:
# /usr/bin/etmmanager-0.7.0
# You can also use shell wildcards:
# /usr/share/etmmanager-0.7.0/*
# This installs documentation files from the top build directory
# into /usr/share/doc/...
# %doc README COPYING
# The advantage of using a real filelist instead of the '-f filelist' trick is
# that rpmbuild will detect if the install section forgets to install
# something that is listed here


%changelog
* Wed Sep 30 2009 prishelec@gmail.com
- packaged etmmanager-0.7.0 version 0.7.0 using the buildservice spec file wizard
* Sat Apr 12 12:00:00 2008 Leonti Bielski <prishelec@gmail.com> 0.6.0
- First public release of ETM Manager
- Works with Time Logger 0.6.0