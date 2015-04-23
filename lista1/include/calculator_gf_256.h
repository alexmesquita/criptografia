#ifndef CALCULATOR_GF_256_H
#define CALCULATOR_GF_256_H

#include <vector>
#include <bitset>

using namespace std;

class CalculatorGF256
{
public:
	CalculatorGF256();
	string	sum(string fx_s, string gx_s);
	string	subtraction(string fx, string gx);
	string	multiplication_mod(string fx, string gx);
	string	division(string fx, string gx);
	
private:
	int degree(bitset<8> mx);
	string multiplicative_inverse(string gx_s);
	bitset<8> mult(bitset<8> x, bitset<8> y);
};

#endif
