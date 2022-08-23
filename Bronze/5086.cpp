#include <iostream>
using namespace std;

int main() {
	while (true) {
		int a, b;
		cin >> a >> b;
		if (a == 0 && b == 0)
			return 0;

		bool isFactor = false, isMultiple = false;
		if (b % a == 0)
			cout << "factor\n";
		else if (a % b == 0)
			cout << "multiple\n";
		else
			cout << "neither\n";
	}
}