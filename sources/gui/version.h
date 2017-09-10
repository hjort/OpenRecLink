#ifndef VERSION_H
#define VERSION_H

namespace AutoVersion
{

  //Date Version Types
  static const char DATE[] = "20";
  static const char MONTH[] = "06";
  static const char YEAR[] = "2016";
  static const char UBUNTU_VERSION_STYLE[] = "16.06";

  //Software Status
  static const char STATUS[] = "Beta";
  static const char STATUS_SHORT[] = "b";

  //Standard Version Type
  static const long MAJOR = 3;
  static const long MINOR = 1;
  static const long BUILD = 824;
  static const long REVISION = 4086;

  //Miscellaneous Version Types
  static const long BUILDS_COUNT = 1579;
#define RC_FILEVERSION 3,1,824,4086
#define RC_FILEVERSION_STRING "3, 1, 824, 4086\0"
  static const char FULLVERSION_STRING[] = "3.1.824.4086";

  //These values are to keep track of your versioning state, don't modify them.
  static const long BUILD_HISTORY = 44;


}
#endif				//VERSION_H
