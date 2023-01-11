#include <iostream>
using namespace std;

int main() {
	int n, nNow;
	cin >> n;
	nNow = n;

	int count = 0;
	do {
		count++;
		int nFront = nNow / 10;
		int nEnd = nNow % 10;
		int newEnd = (nFront + nEnd) % 10;
		nNow = nEnd * 10 + newEnd;
	} while (n != nNow);

	cout << count;
}