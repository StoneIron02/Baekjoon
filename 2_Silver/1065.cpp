#include <iostream>
using namespace std;

bool check(int i) {
	bool result = true;
	int w1 = i % 10;
	int w2 = i / 10;
	int w = (w2 % 10) - w1;
	while (w2 != 0) {
		if ((w2 % 10) - w1 != w)
			return false;
		w1 = w2 % 10;
		w2 = w2 / 10;
	}
	return result;
}

int main() {
	int n;
	cin >> n;

	int count = 0;
	for (int i = 1; i <= n; i++) {
		if(check(i)) count++;
	}
	cout << count;
}