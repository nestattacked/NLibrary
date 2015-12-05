#ifdef _NLIBHEAP_
#define _NLIBHEAP_

namespace nlib{
	namespace heap{

		template<class T>
		void heapAdj(T *root, unsigned int index, int direction){
			;
		}

		template<class T>
		void makeMaxHeap(T *root, unsigned int size);

		template<class T>
		void makeMinHeap(T *root, unsigned int size);

		template<class T>
		T getMax();

		template<class T>
		T getMin();

		template<class T>
		void insertMax(T value);

		template<class T>
		void insertMin(T value);

	}
}

#endif
