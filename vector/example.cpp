#include"nlibvector.h"
#include<iostream>

using std::cout;
using std::endl;
using nlib::vector::Vector;

int main(){
	Vector<int> v(100);
	for(unsigned int i=0;i<100;i++)
		v[i]=(int)(i+1);
	cout<<"pop vector: "<<v.backPop()<<endl;
	cout<<"push vector with 999 ..."<<endl;
	v.backPush(999);
	cout<<"pop vector: "<<v.backPop()<<endl;
	cout<<"89th element: "<<v[88]<<endl;
	cout<<"size of vector: "<<v.count()<<endl;
	return 0;
}
