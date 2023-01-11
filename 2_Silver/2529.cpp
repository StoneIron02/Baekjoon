#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string maxStr = "";
string minStr = "";

void find(vector<char>& compare) { // 2 -> 3°³ -> 012 ~ 789 => 0 < 8
	vector<int> num(compare.size() + 1);
	for (int i = 0; i < 10 - compare.size(); i++) {
		for (int j = 0; j < compare.size() + 1; j++) {
			num[j] = i + j;
		}

		do {
			bool flag = true;
			for (int j = 0; j < compare.size(); j++) {
				if (compare[j] == '<') {
					if (num[j] > num[j + 1]) {
						flag = false;
						break;
					}
				}
				else if (compare[j] == '>') {
					if (num[j] < num[j + 1]) {
						flag = false;
						break;
					}
				}
			}

			if (flag) {
				string str = "";
				for (int j = 0; j < compare.size() + 1; j++) {
					str += num[j] + '0';
				}
				maxStr = str;
				if (minStr == "") {
					minStr = str;
				}
			}
		} while (next_permutation(num.begin(), num.end()));
	}
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int k;
	cin >> k;
	vector<char> compare(k);
	for (int i = 0; i < k; i++)
		cin >> compare[i];
	find(compare);
	cout << maxStr << "\n" << minStr;
}