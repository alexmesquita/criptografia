/* 
 * C++ Program to Implement Miller Rabin Primality Test
 */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#define ll long long
using namespace std;
 
/* 
 * calculates (a * b) % c taking into account that a * b might overflow 
 */
ll mulmod(ll a, ll b, ll mod)
{
    ll x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {    
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b = b >> 1;
    }
    return x % mod;
}
/* 
 * modular exponentiation
 */
ll modulo(ll base, ll exponent, ll mod)
{
    ll x = 1;
    ll y = base;
    while (exponent > 0)
    {
        if (exponent&1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent >> 1;
    }
    return x % mod;
}
 
/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
bool Miller(ll p,int iteration)
{
    if (p < 2)
    {
        return false;
    }
    if (p != 2 && (p&1) == 0)
    {
        return false;
    }
    ll s = p - 1;
    while ((s&1) == 0)
    {
        s = s >> 1;
    }
    for (int i = 0; i < iteration; i++)
    {
        ll a = rand() % (p - 1) + 1, temp = s;
        ll mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && (temp&1) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    srand (time(NULL));
    ll num;
    cout << "Enter integer to test primality: " ;
    
    cin >> num;

    int iteration = (rand() % 100) + 2;
    if (Miller(num, iteration))
        cout << num << " is prime with precision " << fixed << setprecision(5)
            << 100-100.0/pow(2, iteration) << endl;
    else
        cout << num << " is not prime" << endl;
    return 0;
}