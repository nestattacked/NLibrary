#ifndef _NLIBUCHAR_
#define _NLIBUCHAR_

namespace nlib{
	namespace uchar{

		class UChar{
			public:
				UChar(const char *ptr);
				int isLetter();
				char buffer[2];
			private:
				int headCount(char head);
		};
		
	}
}

#endif
