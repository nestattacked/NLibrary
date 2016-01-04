#include"nlibnextperm.h"
#include<iostream>

using std::cout;
using std::endl;
using nlib::nextperm::next_perm;

int main(){
	int values[4] = {0,1,2,3};

	cout<<"origin values:"<<endl;
	cout<<values[0]<<' '<<values[1]<<' '<<values[2]<<' '<<values[3]<<endl;

	cout<<"all permutation:"<<endl;
	do{
		cout<<values[0]<<' '<<values[1]<<' '<<values[2]<<' '<<values[3]<<endl;
	}while(next_perm(values,values+3));
	return 0;
}
