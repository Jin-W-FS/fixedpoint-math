#ifndef FIXED_POINT_MATH_H
#define FIXED_POINT_MATH_H

#include <stdlib.h>
#include <stdint.h>

#define BASETYPE int32_t
#define FIXEDLEN 11		// length of decimal bits

typedef BASETYPE fixed;

#define int2fixed(x) ((x) << FIXEDLEN)
#define fixed2int(x) ((x) >> FIXEDLEN)			// get integer part
#define fixdecimal(x) ((x) & ((1<<FIXEDLEN)-1))	// get decimal part

#define float2fixed(x)	((fixed)((x) * (1<<FIXEDLEN)))
#define fixed2float(x)  ((x) / ((float)(1<<FIXEDLEN)))
#define fixed(x)	float2fixed(x)

#define fixabs(x)	((fixed)labs(x))
static inline BASETYPE fixround(fixed x) {
	BASETYPE y = x >> (FIXEDLEN-1);
	return (y >> 1) + (y & 1);
}

// add, sub and compare operations is the same as BASETYPE
// fixed * int -> fixed or fixed / int -> fixed is the same as BASETYPE
static inline fixed fixmul(fixed x, fixed y){
	return fixed2int(x) * y + fixround(fixdecimal(x) * y);
}
static inline fixed fixdiv(fixed x, fixed y) {
	ldiv_t qr = ldiv(x, y);
	return int2fixed(qr.quot) + int2fixed(qr.rem) / y;
}

static inline fixed fixsqrt(fixed y)
{	// with Newton method
	fixed x;
	if (y <= 0) return 0;
	// initial guess
	if (1) {
		x = int2fixed(1);
		long mask = int2fixed(-2);
		while (y & mask) {
			x <<= 1;
			mask <<= 2;
		}
	} else {
		x = y / 2;
	}
	// loop
	while (1) {
		fixed x2 = fixmul(x, x);
		fixed dy = y - x2;
		fixed dx = fixdiv(dy, x*2);
		//printf("x=%f, x2=%f, dy=%f, dx=%f\n",
		//	fixed2float(x), fixed2float(x2),
		//	fixed2float(dy), fixed2float(dx));
		if (dx == 0) return x;
		// if (fixabs(dx) < int2fixed(1) / 2) return x;
		x += dx;
	}
}

#endif