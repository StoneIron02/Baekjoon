#include <iostream>
using namespace std;

int d(int n) {
	int nNow = n;
	int newN = n;
	while (!(nNow / 10 == 0 && nNow % 10 == 0)) {
		newN += nNow % 10;
		nNow /= 10;
	}
	return newN;
}

int main() {
	bool isSelfNum[10000];
	for (int i = 1; i <= 10000; i++) {
		isSelfNum[i - 1] = true;
	}
	for (int i = 1; i <= 10000; i++) {
		int dResult = d(i);
		if (dResult <= 10000)
			isSelfNum[dResult - 1] = false;
		if (isSelfNum[i - 1])
			cout << i << "\n";
	}
}