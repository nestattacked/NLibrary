#ifndef _NLIBSORT_
#define _NLIBSORT_

#include"../base/nlibbase.h"
#include<stdlib.h>

namespace nlib{
	namespace sort{

		//bubbleSort
		template<class T>
		void bubbleSort(T *begin, size_t size){
			for(int i=size-2;i>=0;i--){
				for(int j=0;j<=i;j++){
					if(begin[j]>begin[j+1])
						nlib::base::swap(begin[j],begin[j+1]);
				}
			}
		}

	}
}

#endif
