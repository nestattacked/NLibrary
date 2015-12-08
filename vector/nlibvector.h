#ifndef _NLIBVECTOR_
#define _NLIBVECTOR_

#include<cstring>

namespace nlib{
	namespace vector{

		template<class T>
		class Vector{
			public:
				Vector(unsigned int size=0);
				~Vector();
				void backPush(const T &value);
				T backPop();
				T& operator[](const unsigned int index);
				unsigned int count();
			private:
				void resize();
				unsigned int size;
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
		unsigned int Vector<T>::count(){
			return size;
		}

		template<class T>
		Vector<T>::Vector(unsigned int size){
			this->size = size;
			capability = init_size;
			while(capability<size){
				capability = capability*step+1;
			}
			ptr = new T[capability];
		}

		template<class T>
		Vector<T>::~Vector(){
			delete[] ptr;
		}

		template<class T>
		void Vector<T>::backPush(const T &value){
			size++;
			if(size>capability){
				capability = capability*step+1;
				resize();
			}
			ptr[size-1] = value;
		}

		template<class T>
		T Vector<T>::backPop(){
			//in order to improve performance, i don't consider about situation when vector is empty
			//code should not call this function when vector is empty!!
			size--;
			return ptr[size];
		}

		template<class T>
		T& Vector<T>::operator[](const unsigned int index){
			//code should not call this function with a wrong parament which is out of range
			//so programer should be careful and niuful :)
			return ptr[index];
		}

		template<class T>
		void Vector<T>::resize(){
			T *temp_ptr = new T[capability];
			std::memcpy(temp_ptr,ptr,sizeof(T)*(size-1));
		}

	}
}

#endif
