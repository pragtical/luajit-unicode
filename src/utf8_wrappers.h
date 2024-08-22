/**
 * Wrappers to provide Unicode (UTF-8) support on Windows.
 *
 * Copyright (c) 2018 Peter Wu <peter@lekensteyn.nl>
 * SPDX-License-Identifier: (GPL-2.0-or-later OR MIT)
 */

#ifdef _WIN32

#ifndef UTF8_WRAPPERS_H
#define UTF8_WRAPPERS_H

#if defined(lib_package_c) || defined(lib_aux_c) || defined(lib_io_c)
#include <stdio.h>  /* for lib_package_c */
FILE *fopen_utf8(const char *pathname, const char *mode);
#define fopen               fopen_utf8
#endif

#ifdef lib_aux_c
#include <stdio.h>
FILE *freopen_utf8(const char *pathname, const char *mode, FILE *stream);
#define freopen             freopen_utf8
#endif

#ifdef lib_io_c
FILE *popen_utf8(const char *command, const char *mode);
#define _popen              popen_utf8
#endif

#ifdef lib_os_c
#include <stdio.h>
#ifndef _MSC_VER
  #define UTF8CRTIMP
#else
  #include <windows.h>
  #define UTF8CRTIMP _ACRTIMP
#endif
UTF8CRTIMP int remove_utf8(const char *pathname);
UTF8CRTIMP int rename_utf8(const char *oldpath, const char *newpath);
UTF8CRTIMP int system_utf8(const char *command);
UTF8CRTIMP char *getenv_utf8(const char *varname);
#define remove              remove_utf8
#define rename              rename_utf8
#define system              system_utf8
#define getenv              getenv_utf8
#endif

#ifdef lib_package_c
#include <windows.h>
DWORD GetModuleFileNameA_utf8(HMODULE hModule, LPSTR lpFilename, DWORD nSize);
HMODULE LoadLibraryExA_utf8(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
#define GetModuleFileNameA  GetModuleFileNameA_utf8
#define LoadLibraryExA      LoadLibraryExA_utf8
#endif

#endif /* UTF8_WRAPPERS_H */
#endif /* _WIN32 */
