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
	for (int i = 0; i < size; ++i)
	{
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
	for (int i = 0; i < size; ++i)
	{
		x[i] = temp[ip_1[i]];
	}

	return x;

}

int main() {
	string plaintext = "abcdefgh";

	cout << (int) plaintext[0] << " " << (int) plaintext[1] << endl;

	int size = plaintext.size();

	vector<int> temp(64);
	vector<vector<int>> bits;
	for (int i = 0; i < size; i+=8)	{
		temp = char_to_bin(plaintext.substr(i,8));

		bits.push_back(temp);
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