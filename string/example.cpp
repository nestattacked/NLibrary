#include"nlibstring.h"
#include<iostream>

int main(){
	const char *ptr = "有一个单词叫做cool。";
	nlib::string::String sentence(ptr);
	std::cout<<sentence.size()<<std::endl;
	return 0;
}
