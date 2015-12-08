#ifndef _NLIBHEAP_
#define _NLIBHEAP_

#include"../vector/nlibvector.h"
#include"../base/nlibbase.h"

namespace nlib{
	namespace heap{

		enum HeapType{Max,Min};

		template<class T>
		class Heap{
			public:
				Heap(HeapType type);
				T get();
				void insert(const T &value);
			private:
				HeapType type;
				nlib::vector::Vector<T> heaps;
				void maxDown();
				void minDown();
				void maxUp();
				void minUp();
				unsigned int getLeftChild(unsigned int index);
				unsigned int getRightChild(unsigned int index);
				unsigned int getParent(unsigned int index);
		};

		template<class T>
		Heap<T>::Heap(HeapType type){
			this->type = type;
		}

		//should not call when it's empty
		template<class T>
		T Heap<T>::get(){
			T temp = heaps[0];
			heaps[0] = heaps.backPop();
			if(type == Max)
				maxDown();
			else
				minDown();
			return temp;
		}

		template<class T>
		void Heap<T>::insert(const T &value){
			heaps.backPush(value);
			if(type == Max)
				maxUp();
			else
				minUp();
		}

		template<class T>
		void Heap<T>::maxDown(){
			unsigned int maxest,size,left,right,present=0;
			size = heaps.count();
			while(1){
				left = getLeftChild(present);
				right = getRightChild(present);
				
				//have no child node
				if(left>=size){
					break;
				}
				else{
					//if only have left child node
					//code will pass next if
					if(heaps[present]>heaps[left])
						maxest = present;
					else
						maxest = left;
					//have two child nodes
					if(right<size){
						if(heaps[right]>heaps[maxest])
							maxest = right;
					}
				}
				if(maxest == present){
					break;
				}
				else{
					nlib::base::swap(heaps[maxest],heaps[present]);
					present = maxest;
				}
			}
		}

		template<class T>
		void Heap<T>::minDown(){
			unsigned int minest,size,left,right,present=0;
			size = heaps.count();
			while(1){
				left = getLeftChild(present);
				right = getRightChild(present);
				
				//have no child node
				if(left>=size){
					break;
				}
				else{
					//if only have left child node
					//code will pass next if
					if(heaps[present]<heaps[left])
						minest = present;
					else
						minest = left;
					//have two child nodes
					if(right<size){
						if(heaps[right]<heaps[minest])
							minest = right;
					}
				}
				if(minest == present){
					break;
				}
				else{
					nlib::base::swap(heaps[minest],heaps[present]);
					present = minest;
				}
			}
		}

		template<class T>
		void Heap<T>::maxUp(){
			unsigned int index = heaps.count()-1;
			while(index!=0){
				unsigned int parent_index = getParent(index);
				if(heaps[index]>heaps[parent_index]){
					nlib::base::swap(heaps[index],heaps[parent_index]);
					index = parent_index;
				}
				else
					break;
			}
		}

		template<class T>
		void Heap<T>::minUp(){
			unsigned int index = heaps.count()-1;
			while(index!=0){
				unsigned int parent_index = getParent(index);
				if(heaps[index]<heaps[parent_index]){
					nlib::base::swap(heaps[index],heaps[parent_index]);
					index = parent_index;
				}
				else
					break;
			}
		}

		template<class T>
		unsigned int Heap<T>::getRightChild(unsigned int index){
			return index*2+1;
		}

		template<class T>
		unsigned int Heap<T>::getLeftChild(unsigned int index){
			return index*2+2;
		}

		template<class T>
		unsigned int Heap<T>::getParent(unsigned int index){
			return (index-1)/2;
		}

	}
}

#endif
