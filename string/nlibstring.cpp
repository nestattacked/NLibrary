#include"nlibstring.h"
#include"../uchar/nlibuchar.h"

namespace nlib{
	namespace string{

		String::String(const char *ptr){
			unsigned int index = 0;
			while(ptr[index] != '\0'){
				int length = nlib::uchar::UChar::headCount(ptr[index]);
				if(length == 0)
					length = 1;
				buffer.backPush(nlib::uchar::UChar(ptr+index));
				index += length;
			}
		}

		unsigned int String::size(){
			return buffer.size();
		}

	}
}
