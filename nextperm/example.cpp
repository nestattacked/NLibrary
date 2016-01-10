#include"nlibnextperm.h"
#include<stdio.h>

using nlib::nextperm::next_perm;

int main(){
	int values[4] = {0,1,2,3};

	printf("origin values:\n%d %d %d %d\n",values[0],values[1],values[2],values[3]);

	printf("all permutation:\n");
	do{
		printf("%d %d %d %d\n",values[0],values[1],values[2],values[3]);
	}while(next_perm(values,values+3));
	return 0;
}
