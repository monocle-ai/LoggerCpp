/*
MIT License

Copyright(c) 2020 Sayantan Roy and Dipanjan Das

Permission is hereby granted, free of charge, to any person obtaining a copy
of this softwareand associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and /or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright noticeand this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#pragma once
#include <string_view>
#include "color_lgf.h"
#include "levelUtils_lgf.h"
#define STRING_VIEW std::string_view
/**
 * This is a dummy class to demonstrate features of the boiler plate.
 */
class LogBuilderTest
{
public:
  /**
   * Default constructor for Dummy (does nothing).
   */
  LogBuilderTest();
  /**
   * Returns a bool.
   * @return Always True.
   */
  template<typename... arguments>
  STRING_VIEW logTest(Lgfypp::Level level, const char* file, int line, const char* function, const arguments&... args);
};

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest.h"
TEST_CASE("we can have tests in headers if we want")
{
    LogBuilderTest logTest;
    CHECK((logTest.logTest(Lgfypp::Level::warn, "Support {} {} {} Architecture ", 32, "bit", "DS")).compare("Support 32 bit DS Architecture "));
}
#endif
