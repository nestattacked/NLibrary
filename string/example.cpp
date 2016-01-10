#include"nlibstring.h"
#include<stdio.h>

int main(){
	const char *ptr = "有一个单词叫做cool。";
	nlib::string::String sentence(ptr);
	printf("%d\n",sentence.size());
	return 0;
}
