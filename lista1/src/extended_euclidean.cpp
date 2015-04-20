#include <vector>
#include "extended_euclidean.h"

using namespace std;

ExtendedEuclidean::ExtendedEuclidean()
{
}

long long
ExtendedEuclidean::x()
{
    return m_x;
}

long long
ExtendedEuclidean::y()
{
    return m_y;
}

long long
ExtendedEuclidean::gcd()
{
    return m_gcd;
}


long long
ExtendedEuclidean::multiplicative_inverse(long long a, long long b)
{
    vector<int> x = {1,0};
    vector<int> y = {0,1};

    long long mod = b;

    while(a%b)
    {
        long long q = a/b;

        long long swap = a;
        a = b;
        b = swap%b;

        long long temp_x, temp_y;

        temp_x = x[0] - (x[1] * q);
        temp_y = y[0] - (y[1] * q);

        x[0] = x[1];
        x[1] = temp_x;

        y[0] = y[1];
        y[1] = temp_y;
    }

    m_x = x[1];
    m_y = y[1];
    m_gcd = b;

    if(x[1] < 0) {
        x[1] += mod;
    }
    return x[1];
}