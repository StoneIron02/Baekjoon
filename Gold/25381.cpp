#include <iostream>
#include <string>
#include <list>
using namespace std;

string S;
list<int> AIndexes;
list<int> BIndexes;
int trialCount = 0;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> S;
	// Push the char data to index array
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'A') {
			AIndexes.push_back(i);
		}
		if (S[i] == 'B') {
			BIndexes.push_back(i);
		}
		if (S[i] == 'C') {
			// Check the removable B-C pair
			if (BIndexes.size() > 0 && BIndexes.front() < i) {
				trialCount++;
				BIndexes.pop_front();
			}
		}
	}
	// Check the removable A-B pair
	while (AIndexes.size() > 0 && BIndexes.size() > 0) {
		if (AIndexes.front() < BIndexes.front()) {
			trialCount++;
			AIndexes.pop_front();
		}
		BIndexes.pop_front();
	}

	cout << trialCount;
}