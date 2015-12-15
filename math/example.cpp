#include"nlibmath.h"
#include<iostream>

int main(){
	unsigned int n,m;
	//gcd test
	std::cout<<"gcd test(input two number): "<<std::endl;
	std::cin>>n>>m;
	unsigned int gcd_res = nlib::math::gcd(n,m);
	std::cout<<"gcd result is: "<<gcd_res<<std::endl;

	//prime test
	std::cout<<"prime test(input a number): "<<std::endl;
	std::cin>>n;
	std::cout<<"prime result is: "<<nlib::math::prime(n)<<std::endl;

	//powmod test
	unsigned int base,power,mod;
	std::cout<<"powmod test(input base power mod): "<<std::endl;
	std::cin>>base>>power>>mod;
	std::cout<<"result is: "<<nlib::math::powmod(base,power,mod)<<std::endl;
	return 0;
}
