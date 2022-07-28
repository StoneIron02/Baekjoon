#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int h, w, n;
		cin >> h >> w >> n;

		int floor = n % h;
		int roomNo;
		if (floor == 0)
			roomNo = (n / h);
		else
			roomNo = (n / h) + 1;

		if (floor == 0)
			cout << h;
		else
			cout << floor;
		if (roomNo < 10)
			cout << 0;
		cout << roomNo << endl;
	}
}