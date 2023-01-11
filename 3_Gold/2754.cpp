#include <iostream>
#include <iomanip>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	map<string, double> score;
	score.insert({ "A+", 4.3 });
	score.insert({ "A0", 4.0 });
	score.insert({ "A-", 3.7 });
	score.insert({ "B+", 3.3 });
	score.insert({ "B0", 3.0 });
	score.insert({ "B-", 2.7 });
	score.insert({ "C+", 2.3 });
	score.insert({ "C0", 2.0 });
	score.insert({ "C-", 1.7 });
	score.insert({ "D+", 1.3 });
	score.insert({ "D0", 1.0 });
	score.insert({ "D-", 0.7 });
	score.insert({ "F", 0.0 });
	string str;
	cin >> str;
	cout << fixed << setprecision(1) << score[str];
}