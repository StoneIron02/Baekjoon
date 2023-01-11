#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	string my, you;
	cin >> my;
	cin >> you;
	if (my.size() < you.size())
		cout << "no";
	else
		cout << "go";
}