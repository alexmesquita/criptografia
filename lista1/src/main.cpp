#include <iostream>
#include "des.h"
#include "extended_euclidean.h"

using namespace std;

int main() {
    string plaintext = "02468aceeca86420", key = "0f1571c947d9e859", chipher_text="da02ce3a89ecac3b";
    Des des;
    cout << des.cipher(plaintext, key) << endl;
    cout << des.decipher(chipher_text, key) << endl;

    ExtendedEuclidean ee;

    cout << endl << ee.multiplicative_inverse(5, 38) << endl;
    return 0;
}
