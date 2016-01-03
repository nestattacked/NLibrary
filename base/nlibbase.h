#ifndef _NLIBBASE_
#define _NLIBBASE_

namespace nlib{
	namespace base{

		//swap two elements
		template<class T>
		void swap(T &v1, T &v2){
			T temp = v1;
			v1 = v2;
			v2 = temp;
		}

		//return max value, only support two elements for now
		template<class T>
		T max(const T &v1, const T &v2){
			return v1>v2?v1:v2;
		}
		
		//return min value, only support two elements for now
		template<class T>
		T min(const T &v1, const T &v2){
			return v1>v2?v2:v1;
		}

	}
}

#endif
