#include <bitset>
#include <string>
#include <vector>
#include "calculator_gf_256.h"

#include <unistd.h>

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
CalculatorGF256::multiplication(string fx, string gx)
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

    bitset<8> r("0000001");
    bitset<8> q("0000000");
    bitset<8> mx("00011011");
    bitset<8> gx(gx_s);

    int degree_mx = 8;
    int degree_gx = degree(gx);
    while(r.any())
    {
        r = mx;

        do
        {
            cout << degree_mx << " " << degree_gx << endl;
            int factor = degree_mx - degree_gx;
            q[factor] = 1;
            cout << q << endl;

            bitset<8> mult;

            //multiplication
            for (int i = 0; i < 8; ++i)
            {
                if(gx.test(i) && i+factor < 8)
                {
                    mult[i+factor] = 1;
                }
            }

            cout << "gx   : " << gx << endl;
            cout << "fator: " << factor << endl;
            cout << "mult : " << mult << endl;
            cout << "mx   : " << r << endl;
            r = (mult ^ r);
            cout << "resto: " << r << endl;
            // break;

            degree_mx = degree(r);
            degree_gx = degree(gx);
            cout << "deg_g: " << degree_gx << endl;
            cout << "deg_m: " << degree_mx << endl;
            // sleep(5);
        } while(degree_mx >= degree_gx && degree_mx);

        cout << "--------------" << endl;
        cout << "saiu" << endl;
        cout << "--------------" << endl;
        mx = gx;
        gx = r;

        degree_mx = degree(mx);
        degree_gx = degree(gx);

        cout << "resto = 0: " << r.any() << endl;
    }
    return to_string(degree_mx);
}

int CalculatorGF256::degree(bitset<8> mx)
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