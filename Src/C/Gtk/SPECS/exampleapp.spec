Summary:        Optimize GTK learning
Name:           exampleapp
License:        GPLv2+ and LGPLv2+ and MIT
Version:        1.0
Release:        1%{?dist}.0

# First source codes, using `tar -cvf` to create tar file, and put tar.gz to %{_sourcedir}.
Source0:        %{name}-%{version}.tar.gz
#URL0:           https://github.com/yusq77/gtk/tree/mainline/examples/application1
#URL1:            https://www.bookstack.cn/read/GTK-3-Chinese-Reference-Manual/content-gtk-questing-index.md

%description
The exampleapp package contains some learning of GTK.

# Using `tar -xf` to tar %{Source0}, and apply all patchs
%prep
%setup -q

# Compiling codes
%build
make -f Makefile.example

# Moving files from %{_builddir} to %{_buildrootdir} directory. .etc cmds: cp ...
# Moving files from %{_sourcedir} to %{_buildrootdir} directory. .etc cmds: install -p -c -m 0644  ...
%install
mkdir -p $RPM_BUILD_ROOT/%{_bindir}
mkdir -p $RPM_BUILD_ROOT/%{_datadir}/icons/hicolor/48x48/apps
mkdir -p $RPM_BUILD_ROOT/%{_datadir}/applications

cp exampleapp $RPM_BUILD_ROOT/%{_bindir}

cp org.gtk.exampleapp.desktop $RPM_BUILD_ROOT/%{_datadir}/applications
sed -i -e "s#@bindir@#/usr/bin/#" $RPM_BUILD_ROOT/%{_datadir}/applications/org.gtk.exampleapp.desktop
sed -i -e "s#@1.0#%{version}-%{release}#" $RPM_BUILD_ROOT/%{_datadir}/applications/org.gtk.exampleapp.desktop
sed -i -e "s#.nd7##" $RPM_BUILD_ROOT/%{_datadir}/applications/org.gtk.exampleapp.desktop

cp exampleapp.png $RPM_BUILD_ROOT/%{_datadir}/icons/hicolor/48x48/apps/

# clean up %{_buildrootdir}
%clean
#rm -rf $RPM_BUILD_ROOT

#%postg

#%postun


# Collect files from %{_buildrootdir} to system directory
%filesg
%defattr(-,root,root)
%{_bindir}/exampleapp
%{_datadir}/applications/org.gtk.exampleapp.desktop
%{_datadir}/icons/hicolor/48x48/apps/exampleapp.png


%changelog
* Fri Dec 13 2019 shuoqi.yu <shuoqi.yu@cs2c.com.cn> - 1.0-1.0
- BASE
