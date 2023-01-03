#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	double n;
	cin >> n;
	vector<double> scores(n);
	for (int i = 0; i < n; i++)
		cin >> scores[i];

	sort(scores.begin(), scores.end());

	for (int i = 0; i < 7; i++)
		cout << fixed << setprecision(3) << scores[i] << "\n";
}