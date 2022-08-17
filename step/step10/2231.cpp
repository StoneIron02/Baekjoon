#include <iostream>
using namespace std;

bool find(int n, int i) {
	int sum = i;
	int now = i;
	while (now > 0) {
		sum += now % 10;
		now /= 10;
	}
	return (n == sum);
}

int main() {
	int n;
	cin >> n;
	int result = 0;
	for (int i = n; i > 0; i--) {
		if (find(n, i))
			result = i;
	}
	cout << result << endl;
}