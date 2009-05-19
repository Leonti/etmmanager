#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion{
	
	//Date Version Types
	static const char DATE[] = "29";
	static const char MONTH[] = "07";
	static const char YEAR[] = "2008";
	static const double UBUNTU_VERSION_STYLE = 8.07;
	
	//Software Status
	static const char STATUS[] = "Alpha";
	static const char STATUS_SHORT[] = "a";
	
	//Standard Version Type
	static const long MAJOR = 0;
	static const long MINOR = 6;
	static const long BUILD = 1;
	static const long REVISION = 7;
	
	//Miscellaneous Version Types
	static const long BUILDS_COUNT = 13;
	#define RC_FILEVERSION 0,6,1,7
	#define RC_FILEVERSION_STRING "0, 6, 1, 7\0"
	static const char FULLVERSION_STRING[] = "0.6.1.7";
	
	//These values are to keep track of your versioning state, don't modify them.
	static const long BUILD_HISTORY = 1;
	

}
#endif //VERSION_h
