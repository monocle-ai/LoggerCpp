#pragma once

#include <stdint.h> // for including different datatype typedefs (e.g. uint32_t)

#define SWFT_LITERAL(txt) (txt);
#define FASTLOG_CONSTEXPR constexpr auto 
#define FSTL_STATIC_CONSTEXPR static FASTLOG_CONSTEXPR

// NAMESPACE
#define FASTLOG_BEGIN namespace FastLog {
#define FASTLOG_END }
#define FASTLOG_SCOPE_ FastLog::

#define COLOR_BEGIN namespace Color {
#define COLOR_END }
