#include <iostream>
#include <string>
using namespace std;

struct lcs {
	int length;
	int path; // left = 001, up = 010, left-up = 100
	lcs() : length(0), path(0) {
	}
	lcs(int length, int path) : length(length), path(path) {
	}
};

lcs** LCS(string str1, string str2) {
	lcs** table = new lcs * [str1.size() + 1];
	for (int i = 0; i <= str1.size(); i++) {
		table[i] = new lcs[str2.size() + 1];
	}
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i - 1] == str2[j - 1]) {
				table[i][j].length = table[i - 1][j - 1].length + 1;
				table[i][j].path = 0b100;
			}
			else if (table[i - 1][j].length >= table[i][j - 1].length) {
				table[i][j].length = table[i - 1][j].length;
				table[i][j].path = 0b010;
			}
			else {
				table[i][j].length = table[i][j - 1].length;
				table[i][j].path = 0b001;
			}
		}
	}
	return table;
}

int LCS_length(lcs** table, int m, int n) {
	return table[m][n].length;
}

int main() {
	string str1, str2;
	cin >> str1 >> str2;
	lcs** table = LCS(str1, str2);
	cout << LCS_length(table, str1.size(), str2.size()) << "\n";
}