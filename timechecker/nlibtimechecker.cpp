#include<stdio.h>
#include<sys/resource.h>
#include"nlibtimechecker.h"

namespace nlib{
	namespace timechecker{

		struct rusage start_rup;
		struct rusage end_rup;

		void startTimer()
		{
			getrusage(RUSAGE_SELF,&start_rup);
		}

		void endTimer()
		{
			getrusage(RUSAGE_SELF,&end_rup);
			long sec = end_rup.ru_utime.tv_sec + end_rup.ru_stime.tv_sec - start_rup.ru_utime.tv_sec - start_rup.ru_stime.tv_sec;
			long usec = end_rup.ru_utime.tv_usec + end_rup.ru_stime.tv_usec - start_rup.ru_utime.tv_usec - start_rup.ru_stime.tv_usec;
			sec += (usec/1000000);
			usec %= 1000000;
			printf("cost time: %ld.%06lds\n",sec,usec);
		}

	}
}
