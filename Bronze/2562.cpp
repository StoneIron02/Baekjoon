#include <iostream>
using namespace std;

int main() {
	int* nums = new int[9];

	for (int i = 0; i < 9; i++) {
		cin >> nums[i];
	}

	int max = nums[0], maxNum = 0;
	for (int i = 1; i < 9; i++) {
		if (max < nums[i]) {
			max = nums[i];
			maxNum = i;
		}
	}

	cout << max << "\n" << maxNum + 1;
}