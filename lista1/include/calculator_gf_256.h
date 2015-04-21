#ifndef CALCULATOR_GF_256_H
#define CALCULATOR_GF_256_H

#include <vector>

using namespace std;

class CalculatorGF256
{
public:
	CalculatorGF256();
	string	sum(string fx_s, string gx_s);
	string	subtraction(string fx, string gx);
	string	multiplication(string fx, string gx);
	string	division(string fx, string gx);
	
private:
};

#endif
