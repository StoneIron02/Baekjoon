#include <iostream>
#include <unordered_set>
using namespace std;

#define C 0
#define D 2
#define E 4
#define F 5
#define G 7
#define A 9
#define B 11
// 12 => 0

int n;
int arr[10000];
unordered_set<int> melody({ A, B, C, D, E, F, G });

int check(int now) {
	for (int i = 0; i < n; i++) {
		now = (now + arr[i] + 24) % 12;
		if (melody.find(now) == melody.end())
			return -1;
	}
	return now;
}

char convert(int m) {
	if (m == C) return 'C';
	if (m == D) return 'D';
	if (m == E) return 'E';
	if (m == F) return 'F';
	if (m == G) return 'G';
	if (m == A) return 'A';
	if (m == B) return 'B';
	return NULL;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int start : melody) {
		int result = check(start);
		if (result != -1) {
			cout << convert(start) << " " << convert(result) << "\n";
		}
	}

}