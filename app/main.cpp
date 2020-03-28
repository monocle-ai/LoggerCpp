// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.

#include "logify.h"
#include "levelUtils_lgf.h"

void someFunction() {
	
}
int main()
{
	Logify_s(Lgfypp::Level::warn,"Support {} {} {} hjkvhjk", 32 ,21, "DS");
	Logify_s( "Support {} {} {} hjkvhjk", 32, 21, "DS");
	
	return 0;
}