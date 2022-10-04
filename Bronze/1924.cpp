#include <iostream>
#include <string>
using namespace std;

int date[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
string day[] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int x, y;
	cin >> x >> y;
	int subdate = 0;
	for (int i = 0; i < (x - 1); i++)
		subdate += date[i];
	subdate += (y - 1);

	cout << day[(subdate % 7)];
}