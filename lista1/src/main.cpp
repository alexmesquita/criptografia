#include <iostream>
#include "calculator_gf_256.h"
#include "des.h"
#include "extended_euclidean.h"

using namespace std;

int main() {
    // string plaintext = "02468aceeca86420", key = "0f1571c947d9e859", chipher_text="da02ce3a89ecac3b";
    // Des des;
    // cout << des.cipher(plaintext, key) << endl;
    // cout << des.decipher(chipher_text, key) << endl;

    // ExtendedEuclidean ee;

    // cout << endl << ee.multiplicative_inverse(5, 38) << endl;

    CalculatorGF256 calc;

    // cout << endl << calc.sum("10101", "0001110") << endl; 
    // cout << calc.subtraction("10101", "0001110") << endl; 
    // cout << calc.multiplication("01010111", "10000011") << endl;

    cout << calc.division("0001", "00111000") << endl;

    return 0;
}
