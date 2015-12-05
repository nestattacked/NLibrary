#ifndef _NLIBTIMECHECKER_
#define _NLIBTIMECHECKER_

#include<sys/resource.h>

namespace nlib{
	namespace timechecker{

		class TimeChecker{
			public:
				//timechecker will have name in future, because class string have't been done
				TimeChecker(){};
				void start();
				void end();
			private:
				struct rusage start_rup;
				struct rusage end_rup;
		};

	}
}

#endif
