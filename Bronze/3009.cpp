	#include <iostream>
	#include <set>
	using namespace std;

	int main() {
		set<int> xList;
		set<int> yList;
		for (int i = 0; i < 3; i++) {
			int x, y;
			cin >> x >> y;
			if (xList.find(x) == xList.end())
				xList.insert(x);
			else
				xList.erase(x);
			if (yList.find(y) == yList.end())
				yList.insert(y);
			else
				yList.erase(y);
		}
		for (auto i : xList)
			cout << i << " ";
		for (auto i : yList)
			cout << i << " ";
	}