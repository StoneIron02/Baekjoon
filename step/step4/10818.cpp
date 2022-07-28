#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;

	int* nums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
		cin.ignore(1, ' ');
	}

	int max = -1000000, min = 1000000;
	for (int i = 0; i < n; i++) {
		if (max < nums[i])
			max = nums[i];
		if (min > nums[i])
			min = nums[i];
	}

	cout << min << " " << max;
}