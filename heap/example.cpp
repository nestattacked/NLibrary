#include<iostream>
#include<iomanip>
#include"nlibheap.h"

using nlib::heap::Heap;
using nlib::heap::Min;
using nlib::heap::Max;
using std::cout;
using std::endl;
using std::setw;

int main(){
	Heap<int> heap1(Min);
	Heap<int> heap2(Max);
	int number[] = {0,43,56,2,90,34,-23,-23,45};
	for(int i=0;i<9;i++){
		heap1.insert(number[i]);
		heap2.insert(number[i]);
	}
	for(int i=0;i<9;i++){
		cout<<setw(5)<<heap1.get();
		cout<<setw(5)<<heap2.get()<<endl;
	}
	return 0;
}
