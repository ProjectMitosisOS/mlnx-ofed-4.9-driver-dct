#ifndef COMPAT_BITS_H
#define COMPAT_BITS_H

/* Include the autogenerated header file */
#include "../../compat/config.h"

#ifdef HAVE_BITS_H
#include_next <linux/bits.h>
#endif

#ifndef GENMASK 
#define GENMASK(h, l) \
	(((~0UL) - (1UL << (l)) + 1) & (~0UL >> (BITS_PER_LONG - 1 - (h))))
#endif

#endif /* COMPAT_BIT_OPS_H */
