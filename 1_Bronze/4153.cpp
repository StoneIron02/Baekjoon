#include <iostream>
#include <set>
using namespace std;

int main() {
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			return 0;
		set<int> set;
		set.insert(a);
		set.insert(b);
		set.insert(c);
		int n = 0;
		int sum = 0;
		for (auto i : set) {
			if (n < 2) {
				sum += i * i;
			}
			else {
				if (sum == (i * i))
					cout << "right\n";
				else
					cout << "wrong\n";
				break;
			}
			n++;
		}
	}
}