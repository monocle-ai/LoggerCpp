#pragma once
#if defined(__GNUC__) && __GNUC__ < 7
# include <experimental/string_view>
# define STRING_VIEW std::experimental::string_view
#else
# include <string_view>

#define STRING_VIEW std::basic_string_view
#endif
class LgfStringView : STRING_VIEW
{

};

