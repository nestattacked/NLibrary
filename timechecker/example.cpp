#include"nlibtimechecker.h"

using nlib::timechecker::startTimer;
using nlib::timechecker::endTimer;

int main(){
	startTimer();
	int i=100000;
	while(i--){
		;
	}
	endTimer();
	return 0;
}
