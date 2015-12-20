#include"nlibuchar.h"

#ifdef _DEBUG_
#include<iostream>
#endif

namespace nlib{
	namespace uchar{

		int UChar::headCount(char head){
			int count = 0;
			while(head&-128){
				count++;
				head<<=1;
			}
			return count;
		}

		UChar::UChar(const char *ptr){
			switch(headCount(ptr[0])){
				case 0:
					buffer[0] = 0;
					buffer[1] = ptr[0];
					break;
				case 2:
					buffer[0] = (ptr[0]>>2)&7;
					buffer[1] = (ptr[1]&63) | ((ptr[0]<<6)&-64);
					break;
				case 3:
					buffer[0] = ((ptr[0]<<4)&-16) | ((ptr[1]>>2)&15);
					buffer[1] = ((ptr[1]<<6)&-64) | (ptr[2]&63);
					break;
				default:
					#ifdef _DEBUG_
					std::cerr<<"warm: wrong utf-8 format is pass into UChar::UChar!"<<std::endl;
					#endif
					;
			}
		}

		int UChar::isLetter(){
			if(buffer[0]==0 && ((buffer[1]>='a'&&buffer[1]<='z')||(buffer[1]>='A'&&buffer[1]<='Z')))
				return 1;
			else
				return 0;
		}

	}
}
