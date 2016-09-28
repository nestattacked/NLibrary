#include"nlibuchar.h"
#include<stdio.h>

using nlib::uchar::UChar;

int main(){
	UChar char1("你");
	UChar char2("a");
	printf("test 你: %d\n",char1.isLetter());
	printf("test a: %d\n",char2.isLetter());
	const char *ptr = "你";
	printf("static function headCount test: %lu\n",UChar::headCount(ptr[0]));
	return 0;
}
