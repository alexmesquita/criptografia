#ifndef EXTENDED_EUCLIDEAN_H
#define EXTENDED_EUCLIDEAN_H

#include <vector>
#include <string>

using namespace std;

class ExtendedEuclidean
{
public:
	ExtendedEuclidean();
	long long multiplicative_inverse(long long a, long long b);
    long long x();
    long long y();
    long long gcd();
private:
	long long m_x, m_y, m_gcd;
};

#endif
