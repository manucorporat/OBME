
/* comment these to skip autoseeding with system time */
#define __DO_AUTOSEED__
#include <time.h>
#include "mersenne.h"

/* Create a length 624 array to store the state of the generator */
unsigned int MT[624];
int idx;
int is_initialized = 0;

/* Initialize the generator from a seed */
void ms_init(int seed) {
    int i;
    unsigned long p;
    
    idx = 0;
    MT[0] = seed;
    for (i=1; i < 624; ++i) { /* loop over each other element */
        p = 1812433253 * (MT[i-1] ^ (MT[i-1] >> 30)) + i;
        MT[i] = p & 0xffffffff; /* get last 32 bits of p */
    }
    is_initialized = 1;
}

/* Extract a tempered pseudorandom number based on the idx-th value,
 calling ms_generate() every 624 numbers */
int ms_rand() {
#ifdef __DO_AUTOSEED__
    if (!is_initialized)
        ms_init((int)time(NULL));
#endif
    
    if (idx == 0)
        ms_generate();
    
    int y = MT[idx];
    y = y ^ (y >> 11);
    y = y ^ ((y << 7) & 2636928640);
    y = y ^ ((y << 15) & 4022730752);
    y = y ^ (y >> 18);
    
    idx = (idx + 1) % 624; /* increment idx mod 624*/
    return y;
}

/* Generate an array of 624 untempered numbers */
void ms_generate() {
    int i, y;
    for (i = 0; i < 624; ++i) {
        y = (MT[i] & 0x80000000) +
        (MT[(i+1) % 624] & 0x7fffffff);
        MT[i] = MT[(i + 397) % 624] ^ (y >> 1);
        if (y % 2) { /* y is odd */
            MT[i] = MT[i] ^ (2567483615);
        }
    }
}