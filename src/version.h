#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion
{

//Date Version Types
static const char DATE[] = "24";
static const char MONTH[] = "09";
static const char YEAR[] = "2009";
static const double UBUNTU_VERSION_STYLE = 9.09;

//Software Status
static const char STATUS[] = "Alpha";
static const char STATUS_SHORT[] = "a";

//Standard Version Type
static const long MAJOR = 0;
static const long MINOR = 7;
static const long BUILD = 0;
static const long REVISION = 7;

//Miscellaneous Version Types
static const long BUILDS_COUNT = 13;
#define RC_FILEVERSION 0,7,0,7
#define RC_FILEVERSION_STRING "0, 7, 0, 7\0"
static const char FULLVERSION_STRING[] = "0.7.0.7";

//These values are to keep track of your versioning state, don't modify them.
static const long BUILD_HISTORY = 1;


}
#endif //VERSION_H
