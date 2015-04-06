#include <iostream>
#include <vector>

using namespace std;

vector<int> char_to_bin(string str) {
	vector<int> temp (64,0);

	int size = str.size();

	for (int i = 0; i < size; ++i)	{
		int count = 7;
		while(str[i]) {
			temp[i*8+count] = str[i]&1;
			str[i] >>= 1;
			count--;
		}
	}
	return temp;
}

vector<int> initial_permutation(vector<int> temp) {
	vector<int> ip = {	57, 49, 41, 33, 25, 17, 9, 1,
						59, 51, 43, 35, 27, 19, 11, 3,
						61, 53, 45, 37, 29, 21, 13, 5,
						63, 55, 47, 39, 31, 23, 15, 7,
						56, 48, 40, 32, 24, 16, 8, 0,
						58,	50, 42, 34, 26, 18, 10, 2,
						60, 52, 44, 36, 28, 20, 12, 4,
						62, 54, 46, 38, 30, 22, 14, 6};

	vector<int> x (64);

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
		linha_string[0] = temp[i*6];
		linha_string[1] = temp[i*6+5];

		string coluna_string = "0000";
		coluna_string[0] = temp[i*8+1];
		coluna_string[1] = temp[i*8+2];
		coluna_string[2] = temp[i*8+3];
		coluna_string[3] = temp[i*8+4];

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

int main() {
	string plaintext = "abcdefgh";

	int size = plaintext.size();

	while(size%8) {
		plaintext += " ";
		size++;
	}

	vector<int> temp(64);
	vector<vector<int>> bits;
	for (int i = 0; i < size; i+=8)	{
		temp = char_to_bin(plaintext.substr(i,8));

		bits.push_back(temp);
	}

	size = bits.size();

	for (int i = 0; i < size; ++i) {
		bits[i] = initial_permutation(bits[i]);

		vector<int> left(32), right(32);

		int size2 = size/2;

		for(int j = 0; j < size2; j++) {
			left[j] = bits[i][j];
			right[j] = bits[i][size2+j-1];
		}

		right = expansion_permutation(right);

		// TODO key

		right = s_boxes(right);

		right = permutation(right);
		
		cout << right.size();
	}

	// for (size_t i = 0; i < bits.size(); ++i)
	// {
	// 	for (size_t j = 0; j < bits[i].size(); ++j)
	// 	{
	// 		if(j%8 == 0) {
	// 			cout << endl;
	// 		}
	// 		cout << bits[i][j];
	// 	}
	// 	cout << "--------" << endl;
	// }
	return 0;
}