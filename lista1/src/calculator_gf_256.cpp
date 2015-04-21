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
CalculatorGF256::multiplication(string fx, string gx)
{
    vector<bitset<8>> powers;
    bitset<8> mod ("00011011");
    bitset<8> aux (fx);

    powers.push_back(aux);
    cout << "passou" << endl;
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
    cout << "----------------" << endl;
    for (int i = 0; i < 8; ++i)
    {
        if(gx[i] == '1')
        {
            cout << powers[i] << endl;
            rx = (rx^powers[7-i]);
        }
    }
    cout << "----------------" << endl;
    return rx.to_string<char,std::string::traits_type,std::string::allocator_type>();
}

// string
// CalculatorGF256::division(string fx, string gx)
// {
//     return "";
// }