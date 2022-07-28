#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> vec, int num) {
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == num)
			return true;
	}
	return false;
}

int main() {
	int nums[10];

	vector<int> mods;

	for (int i = 0; i < 10; i++) {
		cin >> nums[i];
	}

	for (int i = 0; i < 10; i++) {
		int mod = nums[i] % 42;
		if (!find(mods, mod))
			mods.push_back(mod);
	}

	cout << mods.size();

}
