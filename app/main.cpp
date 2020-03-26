// include directory added to visual studio VC++ directory, don't need relative path.
// TODO: remove this comment, later.

#include "logify.h"


int main()
{	
	LOGFY(debug , "Foo: %d", 32);
	return 0;
}
