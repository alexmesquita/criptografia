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