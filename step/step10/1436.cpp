#include <iostream>
#include <string>
using namespace std;

bool isContain666(int num) {
	int stack6 = 0;
	while (num > 0) {
		if (num % 10 == 6)
			stack6++;
		else
			stack6 = 0;

		if (stack6 >= 3)
			return true;

		num /= 10;
	}
	return false;
}

int main() {
	int n;
	cin >> n;
	int count = 0;
	int i = 666;
	while (true) {
		if (isContain666(i))
			count++;

		if (count == n) {
			cout << i << endl;
			return 0;
		}
		i++;
	}
}