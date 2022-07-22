//
// Copyright (c) Microsoft. All rights reserved.
// See https://aka.ms/azai/license202106 for the full license information.
//

#pragma once

// TODO: TFS#3671215 - Vision: C/C++ azac_api* files are in shared include directory, speech and vision share

#ifndef AZAC_SUPRESS_COMMON_INCLUDE_FROM_DIAGNOSTICS
#define AZAC_SUPRESS_DIAGNOSTICS_INCLUDE_FROM_COMMON
#include <azac_api_c_common.h>
#undef AZAC_SUPRESS_DIAGNOSTICS_INCLUDE_FROM_COMMON
#endif

#include <stdarg.h>
#include <stddef.h>

AZAC_API diagnostics_log_start_logging(AZAC_HANDLE hpropbag, void* reserved);
AZAC_API diagnostics_log_apply_properties(AZAC_HANDLE hpropbag, void* reserved);
AZAC_API diagnostics_log_stop_logging();

AZAC_API_(void) diagnostics_log_format_message(char *buffer, size_t bufferSize, int level, const char* pszTitle, const char* fileName, const int lineNumber, const char* pszFormat, va_list argptr);

AZAC_API_(void) diagnostics_log_trace_string(int level, const char* pszTitle, const char* fileName, const int lineNumber, const char* psz);
AZAC_API_(void) diagnostics_log_trace_message(int level, const char* pszTitle, const char* fileName, const int lineNumber, const char* pszFormat, ...);
AZAC_API_(void) diagnostics_log_trace_message2(int level, const char* pszTitle, const char* fileName, const int lineNumber, const char* pszFormat, va_list argptr);

typedef void(*DIAGNOSTICS_CALLBACK_FUNC)(const char *logLine);
AZAC_API diagnostics_logmessage_set_callback(DIAGNOSTICS_CALLBACK_FUNC callback);

AZAC_API_(void) diagnostics_log_memory_start_logging();
AZAC_API_(void) diagnostics_log_memory_stop_logging();

AZAC_API_(size_t) diagnostics_log_memory_get_line_num_oldest();
AZAC_API_(size_t) diagnostics_log_memory_get_line_num_newest();
AZAC_API__(const char*) diagnostics_log_memory_get_line(size_t lineNum);

AZAC_API_(void) diagnostics_log_memory_dump_to_stderr();
AZAC_API_(void) diagnostics_log_memory_dump(const char* filename, const char* linePrefix, bool emitToStdOut, bool emitToStdErr);
AZAC_API_(void) diagnostics_log_memory_dump_on_exit(const char* filename, const char* linePrefix, bool emitToStdOut, bool emitToStdErr);
