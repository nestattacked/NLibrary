#ifndef _NLIBNEXTPERM_
#define _NLIBNEXTPERM_

#ifdef _DEBUG_
#include<stdio.h>
#endif

#include"../base/nlibbase.h"

namespace nlib{
	namespace nextperm{
		
		//operator < must be defined
		//all elements must be different
		template<class T>
		int next_perm(T *begin, T *end){
			#ifdef _DEBUG_
			//some code to check nothing is same from begin to end
			//fix in future, because we need some data struction likes set  which haven't been realized
			#endif
			T *max = end;
			while( max!=begin && (*max)<(*(max-1)) ){
				max--;
			}
			if(max==begin)
				return 0;
			T *min = max;
			max--;
			for(T *i = end;i!=max;i--){
				if((*max)<(*i) && (*i)<(*min))
					min = i;
			}
			nlib::base::swap(*max,*min);
			nlib::base::reverse(max+1,end);
			return 1;
		}

	}
}

#endif
