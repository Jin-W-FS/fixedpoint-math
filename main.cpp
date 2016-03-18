#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "fixedpoint.h"
#include "timeit.h"

int main(int argc, char* argv[])
{
	int i;
	for (i = 1000; i > 0; --i) {
		float f1 = fixed2float(fixsqrt(int2fixed(i)));
		float f2 = sqrtf(i);
		float diff = f1 - f2;
		printf("%d\t%.2f\t%.2f\t%.2f\n", i, f1, f2, diff);
		assert(fabsf(diff) < fixed2float(2));
	}
	TIMEIT(1000, for (i = 1000; i > 0; --i) fixsqrt(int2fixed(i)));
	system("pause");
	return 0;
}
