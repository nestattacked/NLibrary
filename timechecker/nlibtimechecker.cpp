#include<iostream>
#include<iomanip>
#include<sys/resource.h>
#include"nlibtimechecker.h"

namespace nlib{
	namespace timechecker{

		void TimeChecker::start()
		{
			getrusage(RUSAGE_SELF,&start_rup);
		}

		void TimeChecker::end()
		{
			getrusage(RUSAGE_SELF,&end_rup);
			long sec = end_rup.ru_utime.tv_sec + end_rup.ru_stime.tv_sec - start_rup.ru_utime.tv_sec - start_rup.ru_stime.tv_sec;
			long usec = end_rup.ru_utime.tv_usec + end_rup.ru_stime.tv_usec - start_rup.ru_utime.tv_usec - start_rup.ru_stime.tv_usec;
			sec += (usec/1000000);
			usec %= 1000000;
			std::cout<<"cost time: "<<sec<<'.'<<std::setfill('0')<<std::setw(6)<<usec<<'s'<<std::endl;

			//clear the settings of cout
			std::cout<<std::setfill(' ')<<std::setw(0);
		}

	}
}
