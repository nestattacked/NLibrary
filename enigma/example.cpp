#include<iostream>
#include"nlibenigma.h"

using std::cout;
using std::endl;
using nlib::enigma::Enigma;

int main(){
	Enigma m;
	m.setSinglePlug('a','e');
	cout<<m.pressKey('a')<<endl;
	cout<<m.decode("helloworld")<<endl;//no space, only letter
	return 0;
}
