
#ifndef REVERSI_RANDOM_UTIL_HPP
#define REVERSI_RANDOM_UTIL_HPP

#include <algorithm>

template <typename I>
I random_element(I begin, I end)
{
	const unsigned long n = std::distance(begin, end);
	const unsigned long rmax = RAND_MAX;
	const unsigned long divisor = (rmax + 1) / n;

	unsigned long k;
	do { k = std::rand() / divisor; } while (k >= n);

	std::advance(begin, k);
	return begin;
}

#endif
