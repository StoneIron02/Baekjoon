#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> line;

void empty(int n, int k) {
	if (n == 1) {
		line[k] += " ";
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			empty(n / 3, n / 3 * i + k);
		}
	}
}

void star(int n, int k) {
	if (n == 1) {
		line[k] += "*";
		return;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i == 1 && j == 1) {
				empty(n / 3, n / 3 * i + k);
			}
			else {
				star(n / 3, n / 3 * i + k);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		line.push_back("");
	star(n, 0);

	for (int i = 0; i < n; i++)
		cout << line[i] << endl;
}