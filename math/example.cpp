#include"nlibmath.h"
#include<stdio.h>

using nlib::math::prime;
using nlib::math::powmod;

int main(){
	unsigned int n,m;
	//gcd test
	printf("gcd test(input two number):\n");
	scanf("%d%d",&n,&m);
	unsigned int gcd_res = nlib::math::gcd(n,m);
	printf("gcd result is: %d\n",gcd_res);

	//prime test
	printf("prime test(input a number):\n");
	scanf("%d",&n);
	printf("prime result is: %d\n",prime(n));

	//powmod test
	unsigned int base,power,mod;
	printf("powmod test(input base power mod):\n");
	scanf("%d%d%d",&base,&power,&mod);
	printf("result is: %d\n",powmod(base,power,mod));
	return 0;
}
