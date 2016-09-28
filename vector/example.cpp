#include"nlibvector.h"
#include<stdio.h>

using nlib::vector::Vector;

int main(){
	Vector<int> v;
	for(unsigned int i=0;i<100;i++)
		v.backPush(i+1);
	printf("pop vector: %d\n",v.backPop());
	printf("push vector with 999 ...\n");
	v.backPush(999);
	printf("pop vector: %d\n",v.backPop());
	printf("89th element: %d\n",v[88]);
	printf("size of vector: %lu\n",v.size());
	return 0;
}
