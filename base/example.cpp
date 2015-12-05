#include<iostream>
#include"nlibbase.h"

using std::cout;
using std::endl;
using nlib::base::swap;
using nlib::base::max;
using nlib::base::min;

int main(){
	int values[3]={0,1,2};

	cout<<"origin values:"<<endl;
	cout<<values[0]<<' '<<values[1]<<' '<<values[2]<<endl;

	swap(values[0],values[1]);
	cout<<"values after swap 0 with 1:"<<endl;
	cout<<values[0]<<' '<<values[1]<<' '<<values[2]<<endl;

	cout<<"max of 0 and 1:"<<endl;
	cout<<max(values[0],values[1])<<endl;

	cout<<"min of 1 and 2:"<<endl;
	cout<<min(values[2],values[1])<<endl;
}
