#
# spec file for package python-tn3270
#
# Copyright (c) 2015 SUSE LINUX GmbH, Nuernberg, Germany.
# Copyright (C) <2008> <Banco do Brasil S.A.>
#
# All modifications and additions to the file contributed by third parties
# remain the property of their copyright owners, unless otherwise agreed
# upon. The license for this file, and modifications and additions to the
# file, is the same license as for the pristine package itself (unless the
# license for the pristine package is not an Open Source License, in which
# case the license is the MIT License). An "Open Source License" is a
# license that conforms to the Open Source Definition (Version 1.9)
# published by the Open Source Initiative.

# Please submit bugfixes or comments via http://bugs.opensuse.org/

%define skip_python2 1

%{?!python_module:%define python_module() python-%{**} python3-%{**}}

Summary:		Python bindings for lib3270/pw3270
Name:			python3-tn3270
Version:		5.2
Release:		0
License:		GPL-2.0
Source:			%{name}-%{version}.tar.xz
URL:			https://github.com/PerryWerneck/python3-tn3270
Group:			Development/Libraries/Python

BuildRoot:		/var/tmp/%{name}-%{version}

BuildRequires:	autoconf >= 2.61
BuildRequires:	automake
BuildRequires:	binutils
BuildRequires:	coreutils
BuildRequires:	gcc-c++
BuildRequires:	m4
BuildRequires:	pkgconfig
BuildRequires:	fdupes
BuildRequires:  python3

BuildRequires:  python-rpm-macros

BuildRequires:	pkgconfig(ipc3270)
BuildRequires:	pkgconfig(python3)

BuildRequires:  %{python_module devel}
BuildRequires:  %{python_module setuptools}

%python_subpackages

%description
This is an extension allowing tn3270 access for python applications
using lib3270 directly or ipc calls to an enabled pw3270 window.

%prep

%setup

NOCONFIGURE=1 ./autogen.sh

%configure --with-python-sitelib=%{python_sitelib}

%build
%python_build

%install
%python_install

mkdir -p %{buildroot}%{_datadir}/appdata
install --mode=644 metainfo.xml %{buildroot}%{_datadir}/appdata/%{name}.metainfo.xml

%clean

%files %python_files
%defattr(-,root,root)

# https://en.opensuse.org/openSUSE:Packaging_for_Leap#RPM_Distro_Version_Macros
%if 0%{?sle_version} > 120200
%doc AUTHORS README.md
%license LICENSE
%else
%doc AUTHORS README.md LICENSE
%endif

%{python_sitearch}/*
%{_datadir}/appdata/*.metainfo.xml

%changelog
