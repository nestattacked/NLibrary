#ifndef _NLIBHEAP_
#define _NLIBHEAP_

#ifdef _DEBUG_
#include<stdio.h>
#endif

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
				size_t getLeftChild(size_t index);
				size_t getRightChild(size_t index);
				size_t getParent(size_t index);
		};

		template<class T>
		Heap<T>::Heap(HeapType type){
			this->type = type;
		}

		//should not call when it's empty
		template<class T>
		T Heap<T>::get(){
			#ifdef _DEBUG_
			if(heaps.size() == 0)
				printf("warm: Heap::get is called when it's empty!\n");
			#endif
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
			size_t maxest,size,left,right,present=0;
			size = heaps.size();
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
			size_t minest,size,left,right,present=0;
			size = heaps.size();
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
			size_t index = heaps.size()-1;
			while(index!=0){
				size_t parent_index = getParent(index);
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
			size_t index = heaps.size()-1;
			while(index!=0){
				size_t parent_index = getParent(index);
				if(heaps[index]<heaps[parent_index]){
					nlib::base::swap(heaps[index],heaps[parent_index]);
					index = parent_index;
				}
				else
					break;
			}
		}

		template<class T>
		size_t Heap<T>::getRightChild(size_t index){
			return index*2+1;
		}

		template<class T>
		size_t Heap<T>::getLeftChild(size_t index){
			return index*2+2;
		}

		template<class T>
		size_t Heap<T>::getParent(size_t index){
			return (index-1)/2;
		}

	}
}

#endif
