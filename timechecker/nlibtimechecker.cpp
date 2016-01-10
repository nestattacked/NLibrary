#include<sys/resource.h>
#include"nlibtimechecker.h"
#include<stdio.h>

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
			printf("cost time: %ld.%6.6lds\n",sec,usec);
		}

	}
}
