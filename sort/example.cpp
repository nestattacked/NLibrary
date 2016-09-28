#include<iostream>
#include<iomanip>
#include"nlibsort.h"

using nlib::sort::bubbleSort;
using std::cout;
using std::setw;
using std::endl;

int main(){
	int number[] = {0,43,23,53,-23,11,0};
	bubbleSort(number,7);
	for(int i=0;i<7;i++)
		cout<<setw(5)<<number[i];
	cout<<endl;
	return 0;
}
