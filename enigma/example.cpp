#include"nlibenigma.h"
#include<stdio.h>

using nlib::enigma::Enigma;

int main(){
	Enigma m;
	m.setSinglePlug('a','e');

	printf("result when pressKay A: %c\n",m.pressKey('a'));

	char res[20];
	m.decode("helloworld",res);

	printf("result when decode helloworld: %s\n",res);

	return 0;
}
