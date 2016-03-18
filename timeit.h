#ifndef TIME_A_CALLING_H
#define TIME_A_CALLING_H

#include <stdio.h>
#include <time.h>

// take care of variable: i__, t0__, t1__:
#define TIMEIT(times, call) do {		\
		int i__;							\
		clock_t t0__ = clock();			\
		for (i__ = 0; i__ < times; i__++ ) {	\
			call;						\
		}								\
		clock_t t1__ = clock();			\
		printf("average running time: %f sec\n", (float)(t1__ - t0__) / times / CLOCKS_PER_SEC);	\
	} while(0)

#endif