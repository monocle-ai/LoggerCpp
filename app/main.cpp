// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.

#include "logify.h"
#include "levelUtils_lgf.h"
#include "version.h"
#include "fmt/color.h"


void someFunction()
{

}
int main()
{
	Log("One Msg");
	Log("format {} one msg", "One Msg");
	Log("format {} {} two args", 2, "teo");
	Log("format {} {} {}  args", "One", "teo", "three");
	Log("format {} {} {} {} {:x}  args", "One", "two", "three", "four", 312321);
	Log("format {} {} {} {:f} {}  args", "One", "two", "three", 2.2, 43);
	printf("format {} {} {} {:f} {}  args", "One", "two", "three", 2.2, 43);
	Logify(warn, "format {} one msg", "sdse Msg");
	Logify(fatal,"format {} one msg", "sdse Msg");
	Logify(info, "format {} one msg", "sdse Msg");
	Logify(warn,"format {} {} {} {:f} {}  args", "One", "two", "three", 2.2, 43);
	Logd("format {} one msg", "sdse Msg");
	//Logd(debug,"format {} {} {} {:f} {}  args", "One", "two", "three", 2.2, 43);
	someFunction();
	std::cout << (Lgfypp::Level::all == Lgfypp::convertToLevel("All")) << std::endl;

	return 0;
}