#include"nlibmath.h"

namespace nlib{
	namespace math{

		//a,b>0 is guarantedd
		unsigned int gcd(unsigned int a, unsigned int b){
			if(b==0){
				return a;
			}
			else{
				return gcd(b,a%b);
			}
		}

		unsigned int powmod(unsigned int base, unsigned int power, unsigned int mod){
			unsigned int res = 1;
			while(power>0){
				if(power&1==1){
					res = (unsigned long long int)res*base%mod;
				}
				base = (unsigned long long int)base*base%mod;
				power = power>>1;
			}
			return res;
		}

		int prime(unsigned int number){
			if(number==1)
				return 0;
			else if(number==2)
				return 1;
			else if(number%2==0)
				return 0;
			else{
				for(int i=3;i*i<=number;i+=2){
					if(number%i==0)
						return 0;
				}
				return 1;
			}
		}

	}
}
