#include"nlibtimechecker.h"

using nlib::timechecker::TimeChecker;

int main(){
	//call start function to begin timer
	TimeChecker tc;
	tc.start();
	int i=100000;
	while(i--){
		;
	}
	//call end function to end timer
	tc.end();
	return 0;
}
