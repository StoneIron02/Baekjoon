#include <iostream>
using namespace std;

int main() {
	bool ascending = true;
	bool descending = true;
	for (int i = 1; i <= 8; i++) {
		int num;
		cin >> num;
		if (num != i)
			ascending = false;
		if (num != (8 - i + 1))
			descending = false;
	}
	if (ascending)
		cout << "ascending";
	else if (descending)
		cout << "descending";
	else
		cout << "mixed";
}