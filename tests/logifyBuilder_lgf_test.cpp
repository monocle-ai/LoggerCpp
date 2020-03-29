#include "logifyBuilder_lgf_test.h"
#include "logifyBuilder_lgf.h"

LogBuilderTest::LogBuilderTest()
{}

template<typename... arguments>
STRING_VIEW LogBuilderTest::logTest(Lgfypp::Level level, const char* file, int line, const char* function, const arguments&... args)
{
    // Do silly things, using some C++17 features to enforce C++17 builds only.
    return Lgfypp::LogBuilder::logStringView(level, file, line, function, args...);
}

#ifdef ENABLE_DOCTEST_IN_LIBRARY
#include "doctest.h"
TEST_CASE("LogBuilderTest")
{
    CHECK(true);
}
#endif