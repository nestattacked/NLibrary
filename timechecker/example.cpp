#include"nlibtimechecker.h"

using nlib::timechecker::TimeChecker;

int main(){
	//call start function to begin timer
	TimeChecker tc;
	tc.start();
	int i=1000000;
	while(i--){
		int j=500;
		while(j--)
			;
	}
	//call end function to end timer
	tc.end();
	return 0;
}
