#include"nlibuchar.h"
#include<iostream>

using std::cout;
using std::endl;
using nlib::uchar::UChar;

int main(){
	UChar char1("你");
	UChar char2("a");
	cout<<"test 你: "<<char1.isLetter()<<endl;
	cout<<"test a: "<<char2.isLetter()<<endl;
	return 0;
}
