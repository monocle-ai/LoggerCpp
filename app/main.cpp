// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.

#include "logify.h"
#include "levelUtils_lgf.h"
#include "version.h"
#include "fmt/color.h"


void someFunction() {

	Logify("das", 21);
	Logify("sayantan");
	Log::warn("{}", "ss");
	getProjectVersion();

	std::string message = fmt::format(fmt::emphasis::bold | fg(fmt::color::dark_golden_rod),
		"The answer is {}", 44);
	Logify("{}", message);
	Logify(LGF::Level::error,"/n{}", "dsayasasssayabnatab!");
}
int main()
{
	Logify(Lgfypp::Level::warn,"Support {} {} {} hjkvhjk", 32 ,21, "DS");
	Logify( "Support {} {} {} hjkvhjk", 32, 21, "DS");
	someFunction();

	return 0;
}