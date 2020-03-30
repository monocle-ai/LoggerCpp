// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.

#include "logify.h"
#include "levelUtils_lgf.h"
#include "version.h"

void someFunction() {

	Logify("das", 21);
	Logify("sayantan");
	Log::warn("{}", "ss");
	getProjectVersion();

}
int main()
{
	Logify(Lgfypp::Level::warn,"Support {} {} {} hjkvhjk", 32 ,21, "DS");
	Logify( "Support {} {} {} hjkvhjk", 32, 21, "DS");
	someFunction();

	return 0;
}