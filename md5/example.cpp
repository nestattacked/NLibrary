#include"nlibmd5.h"
#include<stdio.h>

using nlib::md5::md5;

int main(){
	unsigned char res[16];
	md5("hello world",res);
	for(int i=0;i<16;i++)
		printf("%.2x",res[i]);
	putchar('\n');
	return 0;
}
