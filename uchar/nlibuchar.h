#ifndef _NLIBUCHAR_
#define _NLIBUCHAR_

#include<stdlib.h>

namespace nlib{
	namespace uchar{

		class UChar{
			public:
				UChar(const char *ptr);
				int isLetter();
				static size_t headCount(char head);
			private:
				char buffer[2];
		};
		
	}
}

#endif
