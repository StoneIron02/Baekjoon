#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> wars;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		wars.insert({ str, i });
	}
	int score = 0;
	vector<string> answers(n);
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < i; j++) {
			if (wars[answers[j]] < wars[str])
				score++;
		}
		answers[i] = str;
	}
	cout << score << "/" << (n * (n - 1) / 2);
}