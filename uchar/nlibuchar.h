#ifndef _NLIBUCHAR_
#define _NLIBUCHAR_

namespace nlib{
	namespace uchar{

		class UChar{
			public:
				UChar(const char *ptr);
				int isLetter();
				static unsigned int headCount(char head);
			private:
				char buffer[2];
		};
		
	}
}

#endif
