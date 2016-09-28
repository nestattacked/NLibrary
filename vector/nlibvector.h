#ifndef _NLIBVECTOR_
#define _NLIBVECTOR_

#ifdef _DEBUG_
#include<stdio.h>
#endif

#include<string.h>
#include<stdlib.h>

namespace nlib{
	namespace vector{

		template<class T>
		class Vector{
			public:
				Vector();
				~Vector();
				void backPush(const T &value);
				T backPop();
				T& operator[](size_t index);
				size_t size();
			private:
				void resize();
				size_t used_size;
				size_t capability;
				const static size_t init_size;
				const static size_t step;
				T *ptr;
		};

		template<class T>
		const size_t Vector<T>::init_size = 15;

		template<class T>
		const size_t Vector<T>::step = 2;

		template<class T>
		size_t Vector<T>::size(){
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
				printf("warm: vector::backPop is called when vector is empty!\n");
			#endif
			used_size--;
			return ptr[used_size];
		}

		template<class T>
		T& Vector<T>::operator[](size_t index){
			//code should not call this function with a wrong parament which is out of range
			//so programer should be careful and niuful :)
			#ifdef _DEBUG_
			if(index>used_size-1)
				printf("warm: vector::operator[] is called but index is out of range!\n");
			#endif
			return ptr[index];
		}

		template<class T>
		void Vector<T>::resize(){
			T *temp_ptr = (T*)malloc(sizeof(T)*capability);
			memcpy(temp_ptr,ptr,sizeof(T)*(used_size-1));
			free(ptr);
			ptr = temp_ptr;
		}

	}
}

#endif
