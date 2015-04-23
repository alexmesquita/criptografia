#include <bitset>
#include <string>
#include <vector>
#include "calculator_gf_256.h"

#include <iostream>

using namespace std;

CalculatorGF256::CalculatorGF256()
{
}

string
CalculatorGF256::sum(string fx_s, string gx_s)
{
    bitset<8> fx (fx_s);
    bitset<8> gx (gx_s);

    bitset<8> rx = (fx ^ gx);

    return rx.to_string<char,std::string::traits_type,std::string::allocator_type>();
}

string
CalculatorGF256::subtraction(string fx, string gx)
{
    return sum(fx, gx);
}

string
CalculatorGF256::multiplication_mod(string fx, string gx)
{
    vector<bitset<8>> powers;
    bitset<8> mod ("00011011");
    bitset<8> aux (fx);

    powers.push_back(aux);
    for (int i = 7; i > 0; i--)
    {
        bitset<8> temp = aux;
        aux <<= 1;
        
        if(temp[7])
        {
            aux = (aux ^ mod);
        }

        powers.push_back(aux);
        
    }

    bitset<8> rx;
    for (int i = 0; i < 8; ++i)
    {
        if(gx[i] == '1')
        {
            rx = (rx^powers[7-i]);
        }
    }
    return rx.to_string<char,std::string::traits_type,std::string::allocator_type>();
}

string
CalculatorGF256::division(string fx_s, string gx_s)
{

    bitset<8> gx_inverse(multiplicative_inverse(gx_s));
    bitset<8> fx(fx_s);
    string result = mult(fx, gx_inverse).to_string<char,std::string::traits_type,std::string::allocator_type>();

    return result;
}

int 
CalculatorGF256::degree(bitset<8> mx)
{
    int degree = 0;
    for (int i = 7; i >= 0; --i)
    {
        if(mx.test(i))
        {
            degree = i;
            break;
        }
    }

    return degree;
}

string
CalculatorGF256::multiplicative_inverse(string gx_s)
{
    bitset<8> r("0000001");
    bitset<8> q("0000000");
    bitset<8> mx("00011011");
    bitset<8> gx(gx_s);

    vector<bitset<8>> v;
    vector<bitset<8>> w;

    v.push_back(r);
    v.push_back(q);
    w.push_back(q);
    w.push_back(r);

    int degree_mx = 8;
    int degree_gx = degree(gx);
    while(r.any())
    {
        r = mx;
        q.reset();
        do
        {
            int factor = degree_mx - degree_gx;
            q[factor] = 1;

            bitset<8> mult;

            //multiplication
            for (int i = 0; i < 8; ++i)
            {
                if(gx.test(i) && i+factor < 8)
                {
                    mult[i+factor] = 1;
                }
            }

            r = (mult ^ r);

            degree_mx = degree(r);
            degree_gx = degree(gx);
        } while(degree_mx >= degree_gx && degree_mx);

        mx = gx;
        gx = r;

        bitset<8> temp;

        temp = (v[0] ^ (mult(v[1], q)));

        v[0] = v[1];
        v[1] = temp;

        temp = (w[0] ^ (mult(w[1], q)));

        w[0] = w[1];
        w[1] = temp;

        degree_mx = degree(mx);
        degree_gx = degree(gx);
    }

    return w[0].to_string<char,std::string::traits_type,std::string::allocator_type>();
}

bitset<8>
CalculatorGF256::mult(bitset<8> x, bitset<8> y)
{
    bitset<8> mult;
    bitset<8> temp;


    for (int i = 0; i < 8; ++i)
    {
        if(x[i])
        {
            temp.reset();
            for(int j = 0; j < 8; j++)
            {
                if(y[j] && i+j < 8)
                {
                    temp[i+j] = 1;
                }
            }
            mult = (mult ^ temp);
        }
    }
    return mult;
}