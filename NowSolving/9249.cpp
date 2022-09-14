#include <iostream>
#include <string>
using namespace std;

int** LCS(string str1, string str2) {
	int** table = new int* [str1.size() + 1];
	for (int i = 0; i <= str1.size(); i++) {
		table[i] = new int[str2.size() + 1] {0};
	}
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				table[i][j] = table[i - 1][j - 1] + 1;
			}
		}
	}
	return table;
}

void print_LCS(int** table, string str, int i, int j) {
	if (i == 0 || j == 0)
		return;
	if (table[i][j] > 0) {
		print_LCS(table, str, i - 1, j - 1);
		cout << str[i - 1];
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	string str1, str2;
	cin >> str1 >> str2;
	int** table = LCS(str1, str2);

	int indexI = 1, indexJ = 1;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (table[i][j] > table[indexI][indexJ]) {
				indexI = i;
				indexJ = j;
			}
		}
	}
	
	cout << table[indexI][indexJ] << "\n";
	print_LCS(table, str1, indexI, indexJ);
}