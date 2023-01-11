#include <iostream>
using namespace std;

int main() {
	int n, x;
	cin >> n >> x;

	int* nums = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	for (int i = 0; i < n; i++) {
		if (nums[i] < x)
			cout << nums[i] << " ";
	}
}