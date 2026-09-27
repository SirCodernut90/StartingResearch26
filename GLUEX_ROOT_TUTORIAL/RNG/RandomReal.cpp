#include "RandomReal.h"
#include <gsl/gsl_rng.h>
#include <sys/time.h>

double RandomReal(double a, double b) {
	struct timeval CurrentTime;
	gettimeofday(&CurrentTime, 0);
	long seed = CurrentTime.tv_sec + CurrentTime.tv_usec;
	
	const gsl_rng_type *T = gsl_rng_mt19937;
	gsl_rng *r = gsl_rng_alloc(T);
	
	gsl_rng_set(r, seed);
	
	double randnum = gsl_rng_uniform(r);

	double appliedRange = randnum * (b-a) + a;

	gsl_rng_free(r);
	
	return appliedRange;
}
