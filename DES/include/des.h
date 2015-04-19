#ifndef DES_H
#define DES_H

#include <vector>
#include <string>

using namespace std;

class Des
{
public:
	Des();
	string cipher(string plaintext, string key);
	string decipher(string cipher_text, string key);
    
private:
	string m_plaintext, m_key, m_cipher_text;
	vector<int> hex_to_bin(string str);
	vector<int> initial_permutation(vector<int> temp);
	vector<int> inverse_initial_permutation(vector<int> temp);
	vector<int> expansion_permutation(vector<int> temp);
	vector<int> permutation(vector<int> temp);
	vector<int> s_boxes(vector<int> temp);
	vector<vector<int>> convert_text(string plaintext);
	vector<int> convert_key(string key);
	vector<int> left_shift(vector<int> temp, int round);
	vector<int> right_shift(vector<int> temp, int round);
	vector<int> decipher_initial_shift(vector<int> temp);
	vector<int> permutation_choice1(vector<int> bits_key);
	vector<int> permutation_choice2(vector<int> ci, vector<int> di);
	vector<int> xor_operation(vector<int> temp1, vector<int> temp2);
};

#endif
