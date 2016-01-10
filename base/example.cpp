#include"nlibbase.h"
#include<stdio.h>

using nlib::base::swap;
using nlib::base::max;
using nlib::base::min;
using nlib::base::reverse;

int main(){
	int values[3]={0,1,2};

	printf("origin values:\n%d %d %d\n",values[0],values[1],values[2]);

	reverse(values,values+2);
	printf("values after reverse:\n%d %d %d\n",values[0],values[1],values[2]);

	swap(values[0],values[1]);
	printf("values after swap 0 with 1:\n%d %d %d\n",values[0],values[1],values[2]);

	printf("max of 0 and 1:\n%d\n",max(values[0],values[1]));

	printf("min of 1 and 2:\n%d\n",min(values[2],values[1]));

	return 0;
}
