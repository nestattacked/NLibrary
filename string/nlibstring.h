#ifndef _NLIBSTRING_
#define _NLIBSTRING_

#include"../vector/nlibvector.h"
#include"../uchar/nlibuchar.h"

namespace nlib{
	namespace string{

		//only support utf-8 encoding
		//store in unicode, two bytes for each character
		class String{
			public:
				String(const char *ptr);
				unsigned int size();
			private:
				nlib::vector::Vector<nlib::uchar::UChar> buffer;
		};

	}
}

#endif
