#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getScore(string str) {
	int time = 0;
	int score = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str.at(i) == 'O') {
			time++;
			score += time;
		}
		else if (str.at(i) == 'X') {
			time = 0;
		}
	}
	return score;
}

int main() {
	int n;
	cin >> n;

	vector<string> results;

	for (int i = 0; i < n; i++) {
		string result;
		cin >> result;
		results.push_back(result);
	}

	for (int i = 0; i < results.size(); i++) {
		cout << getScore(results[i]) << "\n";
	}
}
