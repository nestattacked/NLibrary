#ifndef _NLIBVECTOR_
#define _NLIBVECTOR_

#ifdef _DEBUG_
#include<iostream>
#endif

#include<cstring>
#include<cstdlib>

namespace nlib{
	namespace vector{

		template<class T>
		class Vector{
			public:
				Vector();
				~Vector();
				void backPush(const T &value);
				T backPop();
				T& operator[](unsigned int index);
				unsigned int size();
			private:
				void resize();
				unsigned int used_size;
				unsigned int capability;
				const static unsigned int init_size;
				const static unsigned int step;
				T *ptr;
		};

		template<class T>
		const unsigned int Vector<T>::init_size = 15;

		template<class T>
		const unsigned int Vector<T>::step = 2;

		template<class T>
		unsigned int Vector<T>::size(){
			return used_size;
		}

		template<class T>
		Vector<T>::Vector(){
			used_size = 0;
			capability = init_size;
			ptr = (T*)malloc(sizeof(T)*capability);
		}

		template<class T>
		Vector<T>::~Vector(){
			free(ptr);
		}

		template<class T>
		void Vector<T>::backPush(const T &value){
			used_size++;
			if(used_size>capability){
				capability = capability*step+1;
				resize();
			}
			ptr[used_size-1] = value;
		}

		template<class T>
		T Vector<T>::backPop(){
			//in order to improve performance, i don't consider about situation when vector is empty
			//code should not call this function when vector is empty!!
			#ifdef _DEBUG_
			if(used_size == 0)
				std::cerr<<"warm: vector::backPop is called when vector is empty!"<<std::endl;
			#endif
			used_size--;
			return ptr[used_size];
		}

		template<class T>
		T& Vector<T>::operator[](unsigned int index){
			//code should not call this function with a wrong parament which is out of range
			//so programer should be careful and niuful :)
			#ifdef _DEBUG_
			if(index<0 || index>used_size-1)
				std::cerr<<"warm: vector::operator[] is called but index is out of range!"<<std::endl;
			#endif
			return ptr[index];
		}

		template<class T>
		void Vector<T>::resize(){
			T *temp_ptr = (T*)malloc(sizeof(T)*capability);
			std::memcpy(temp_ptr,ptr,sizeof(T)*(used_size-1));
			free(ptr);
			ptr = temp_ptr;
		}

	}
}

#endif
