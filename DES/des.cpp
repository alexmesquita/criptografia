#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<int> hex_to_bin(string str) {
	vector<int> result;

	int size = str.size();
	string temp = "";

	for (int i = 0; i < size; ++i)	{
		switch (str[i])
		{
			case '0': temp.append ("0000"); break;
			case '1': temp.append ("0001"); break;
			case '2': temp.append ("0010"); break;
			case '3': temp.append ("0011"); break;
			case '4': temp.append ("0100"); break;
			case '5': temp.append ("0101"); break;
			case '6': temp.append ("0110"); break;
			case '7': temp.append ("0111"); break;
			case '8': temp.append ("1000"); break;
			case '9': temp.append ("1001"); break;
			case 'a': temp.append ("1010"); break;
			case 'b': temp.append ("1011"); break;
			case 'c': temp.append ("1100"); break;
			case 'd': temp.append ("1101"); break;
			case 'e': temp.append ("1110"); break;
			case 'f': temp.append ("1111"); break;
		}
	}

	size = temp.size();

	for (int i = 0; i < size; ++i)
	{
		result.push_back(temp[i]-'0');
	}
	return result;
}

vector<int> initial_permutation(vector<int> temp) {
	vector<int> ip = {	57, 49, 41, 33, 25, 17,  9, 1,
						59, 51, 43, 35, 27, 19, 11, 3,
						61, 53, 45, 37, 29, 21, 13, 5,
						63, 55, 47, 39, 31, 23, 15, 7,
						56, 48, 40, 32, 24, 16,  8, 0,
						58,	50, 42, 34, 26, 18, 10, 2,
						60, 52, 44, 36, 28, 20, 12, 4,
						62, 54, 46, 38, 30, 22, 14, 6};

	vector<int> x(64);

	int size = ip.size();
	for (int i = 0; i < size; ++i) {
		x[i] = temp[ip[i]];
	}
	return x;
}

vector<int> inverse_initial_permutation(vector<int> temp) {
	vector<int> ip_1 = {39, 7, 47, 15, 55, 23, 63, 31,
						38, 6, 46, 14, 54, 22, 62, 30,
						37, 5, 45, 13, 53, 21, 61, 29,
						36, 4, 44, 12, 52, 20, 60, 28,
						35, 3, 43, 11, 51, 19, 59, 27,
						34, 2, 42, 10, 50, 18, 58, 26,
						33, 1, 41, 9, 49, 17, 57, 25,
						32, 0, 40, 8, 48, 16, 56, 24};

	vector<int> x (64);

	int size = ip_1.size();
	for (int i = 0; i < size; ++i) {
		x[i] = temp[ip_1[i]];
	}
	return x;
}

vector<int> expansion_permutation(vector<int> temp) {
	vector<int> ep = {31,  0,  1,  2,  3,  4,
						 3,  4,  5,  6,  7,  8,
						 7,  8,  9, 10, 11, 12,
						11, 12, 13, 14, 15, 16,
						15, 16, 17, 18, 19, 20,
						19,	20, 21, 22, 23, 24,
						23, 24,	25, 26, 27, 28, 
						27, 28, 29, 30, 31,  0};

	vector<int> x (48);

	int size = ep.size();
	for (int i = 0; i < size; ++i) {
		x[i] = temp[ep[i]];
	}
	return x;
}

vector<int> permutation(vector<int> temp) {
	vector<int> ep = {	15,  6, 19, 20, 28, 11, 27, 16,
						 0, 14, 22, 25,  4, 17, 30,  9,
						 1,  7, 23, 13, 31, 26,  2,  8,
						18, 12, 29,  5, 21, 10,  3, 24};

	vector<int> x (32);

	int size = ep.size();
	for (int i = 0; i < size; ++i) {
		x[i] = temp[ep[i]];
	}
	return x;
}

vector<int> s_boxes(vector<int> temp) {
	vector<int> s1 = {	14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
						0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
						4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
						15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

	vector<int> s2 = {	15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
						3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
						0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
						13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

	vector<int> s3 = {	10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
						13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
						13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
						1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

	vector<int> s4 = {	7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
						13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
						10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
						3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

	vector<int> s5 = {	2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
						14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
						4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
						11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

	vector<int> s6 = {	12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
						10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
						9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
						4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

	vector<int> s7 = {	4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
						13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
						1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
						6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

	vector<int> s8 = {	13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
						1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
						7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
						2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

	vector<vector<int>> ss = {s1, s2, s3, s4, s5, s6, s7, s8};
	vector<int> x (32);

	for (int i = 0; i < 8; ++i)	{
		string linha_string = "00";
		linha_string[0] = temp[i*6]+'0';
		linha_string[1] = temp[i*6+5]+'0';

		string coluna_string = "0000";
		coluna_string[0] = temp[i*6+1]+'0';
		coluna_string[1] = temp[i*6+2]+'0';
		coluna_string[2] = temp[i*6+3]+'0';
		coluna_string[3] = temp[i*6+4]+'0';

		long linha = strtol(linha_string.c_str(), NULL, 2);
		long coluna = strtol(coluna_string.c_str(), NULL, 2);

		int result = ss[i][coluna+16*linha];

		int count = 3;
		while(result){
			x[i*4+count] = result&1;
			result >>= 1;
			count--;
		}
	}
	return x;
}

vector<vector<int>> convert_text(string plaintext) {
	int size = plaintext.size();

	vector<int> temp(64);
	vector<vector<int>> bits;
	for (int i = 0; i < size; i+=16)	{
		temp = hex_to_bin(plaintext.substr(i,16));

		bits.push_back(temp);
	}

	return bits;
}

vector<int> convert_key(string key) {
	vector<int> bits_key(64);
	
	bits_key = hex_to_bin(key);

	return bits_key;
}

vector<int> left_shift(vector<int> temp, int round) {
	vector<int> number_of_rotations = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

	for (int i = 0; i < number_of_rotations[round%16]; ++i)
	{
		int first = temp[0];
		for(int j = 0; j < 27; j++) {
			temp[j] = temp[j+1];
		}
		temp[27] = first;
	}
	return temp;
}

vector<int> right_shift(vector<int> temp, int round) {
	vector<int> number_of_rotations = {0,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};

	for (int i = 0; i < number_of_rotations[round%16]; ++i)
	{
		int last = temp[27];
		for(int j = 27; j > 0; j--) {
			temp[j] = temp[j-1];
		}
		temp[0] = last;
	}
	return temp;
}

vector<int> decipher_initial_shift(vector<int> temp) {
	for (int i = 0; i < 28; ++i)
	{
		int last = temp[27];
		for(int j = 27; j > 0; j--) {
			temp[j] = temp[j-1];
		}
		temp[0] = last;
	}
	return temp;
}

vector<int> permutation_choice1(vector<int> bits_key) {

	vector<int> pc1c = {56, 48, 40, 32, 24, 16,  8,
						 0, 57, 49, 41, 33, 25, 17,
						 9,  1, 58, 50, 42, 34, 26,
						18, 10,  2, 59, 51, 43, 35,
						62, 54, 46, 38, 30, 22, 14,
						 6, 61, 53, 45, 37, 29, 21, 
						13,  5, 60, 52, 44, 36, 28,
						20, 12,  4, 27, 19, 11,  3};

	vector<int> result(56);

	for(int i = 0; i < 56; i++) {
		result[i] = bits_key[pc1c[i]];
	}

	return result;
}

vector<int> permutation_choice2(vector<int> ci, vector<int> di) {
	vector<int> pdc2 = {13, 16, 10, 23,  0,  4,  2, 27,
						14,  5, 20,  9, 22, 18, 11,  3, 
						25,  7, 15,  6, 26, 19, 12,  1, 
						40, 51, 30, 36, 46, 54, 29, 39, 
						50, 44, 32, 47, 43, 48, 38, 55, 
						33, 52, 45, 41, 49, 35, 28, 31};

	vector<int> key_choice2 (48);
	for (int i = 0; i < 48; ++i)
	{
		if(pdc2[i] < 28) {
			key_choice2[i] = ci[pdc2[i]];
		}
		else {
			key_choice2[i] = di[pdc2[i] - 28];
		}
	}

	return key_choice2;
}

vector<int> xor_operation(vector<int> temp1, vector<int> temp2) {
	int size = temp1.size();

	for (int i = 0; i < size; ++i)
	{
		temp1[i] = temp1[i] ^ temp2[i];
	}

	return temp1;
}

string chipher(string plaintext, string key) {

	vector<vector<int>> bits = convert_text(plaintext);

	vector<int> bits_key = convert_key(key);

	string chipher_bits;

	int size = bits.size();

	bits_key = permutation_choice1(bits_key);

	vector<int> ci(28), di(28);

	for(int j = 0; j < 28; j++) {
		ci[j] = bits_key[j];
		di[j] = bits_key[j+28];
	}

	for (int i = 0; i < size; ++i) {
		bits[i] = initial_permutation(bits[i]);		
		vector<int> left(32), right(32), temp_right(32);
		int size2 = left.size();

		for(int j = 0; j < size2; j++) {
			left[j] = bits[i][j];
			right[j] = bits[i][size2+j];
			temp_right[j] = bits[i][size2+j];
		}

		for(int k = 0; k < 16; k++) {
			right = expansion_permutation(right);

			ci = left_shift(ci, k);
			di = left_shift(di, k);

			vector<int> key_choice2 = permutation_choice2(ci, di);

			right = xor_operation(right, key_choice2);

			right = s_boxes(right);
			
			right = permutation(right);

			right = xor_operation(right, left);
			left = temp_right;
			temp_right = right;
		}


		// 32 bits swap
		// a direita vem antes da esquerda
		vector<int> result(64);
		for (int j = 0; j < 32; ++j)
		{
			result[j] = right[j];
			result[j+32] = left[j];
		}

		result = inverse_initial_permutation(result);

		for (int j = 0; j < 64; ++j)
		{
			chipher_bits += (result[j] + '0');
		}
	}

	string chipher_text = "";

	size = chipher_bits.size();
	stringstream ss;
	for (int i = 0; i < size; i+=4)
	{
		string temp = chipher_bits.substr(i, 4);

		ss << hex << strtol(temp.c_str(), NULL, 2);
	}
	ss >> chipher_text;
	return chipher_text;
}

string decipher(string chipher_text, string key) {
	vector<vector<int>> bits = convert_text(chipher_text);

	vector<int> bits_key = convert_key(key);

	string dechipher_bits;

	int size = bits.size();

	bits_key = permutation_choice1(bits_key);


	vector<int> ci(28), di(28);

	for(int j = 0; j < 28; j++) {
		ci[j] = bits_key[j];
		di[j] = bits_key[j+28];
	}
	ci = decipher_initial_shift(ci);
	di = decipher_initial_shift(di);

	for (int i = 0; i < size; ++i) {
		bits[i] = initial_permutation(bits[i]);		
		vector<int> left(32), right(32), temp_right(32);
		int size2 = left.size();

		for(int j = 0; j < size2; j++) {
			left[j] = bits[i][j];
			right[j] = bits[i][size2+j];
			temp_right[j] = bits[i][size2+j];
		}

		for(int k = 0; k < 16; k++) {
			right = expansion_permutation(right);

			ci = right_shift(ci, k);
			di = right_shift(di, k);

			vector<int> key_choice2 = permutation_choice2(ci, di);

			right = xor_operation(right, key_choice2);

			right = s_boxes(right);
			
			right = permutation(right);

			right = xor_operation(right, left);
			left = temp_right;
			temp_right = right;
		}


		// 32 bits swap
		// a direita vem antes da esquerda
		vector<int> result(64);
		for (int j = 0; j < 32; ++j)
		{
			result[j] = right[j];
			result[j+32] = left[j];
		}

		result = inverse_initial_permutation(result);

		for (int j = 0; j < 64; ++j)
		{
			dechipher_bits += (result[j] + '0');
		}
	}

	string dechipher_text = "";

	size = dechipher_bits.size();
	stringstream ss;
	for (int i = 0; i < size; i+=4)
	{
		string temp = dechipher_bits.substr(i, 4);

		ss << hex << strtol(temp.c_str(), NULL, 2);
	}
	ss >> dechipher_text;
	return dechipher_text;
}

int main() {
	string plaintext = "02468aceeca86420", key = "0f1571c947d9e859", chipher_text="da02ce3a89ecac3b";

	cout << chipher(plaintext, key) << endl;
	cout << decipher(chipher_text, key) << endl;

	return 0;
}