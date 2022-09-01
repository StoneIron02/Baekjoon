#include <iostream>
using namespace std;

int* arr;
int* dp_increase;
int* dp_decrease;

int dynamic_programming(int n) {
	dp_increase = new int[n + 1];
	dp_decrease = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		dp_increase[i] = 1;
		dp_decrease[n + 1 - i] = 1;
		for (int j = 1; j < i; j++) {
			if (arr[j] < arr[i])
				dp_increase[i] = (dp_increase[i] < dp_increase[j] + 1 ? dp_increase[j] + 1 : dp_increase[i]);

			if (arr[n + 1 - j] < arr[n + 1 - i])
				dp_decrease[n + 1 - i] = (dp_decrease[n + 1 - i] < dp_decrease[n + 1 - j] + 1 ? dp_decrease[n + 1 - j] + 1 : dp_decrease[n + 1 - i]);
		}
	}
	int max = -1;
	for (int i = 1; i <= n; i++) {
		max = (dp_increase[i] + dp_decrease[i] - 1 > max ? dp_increase[i] + dp_decrease[i] - 1 : max);
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		arr[i] = num;
	}
	cout << dynamic_programming(n);
}