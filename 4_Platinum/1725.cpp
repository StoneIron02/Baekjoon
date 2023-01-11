#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int maxRect(vector<int>& height) {
	stack<int> stack;
	stack.push(0);
	int max = 0;
	for (int i = 1; i < height.size(); i++) {
		while (!stack.empty() && height[stack.top()] > height[i]) {
			int h = height[stack.top()]; stack.pop();
			int w = (stack.empty() ? i : (i - 1) - stack.top());
			int rect = h * w;
			max = (rect > max ? rect : max);
		}
		stack.push(i);
	}
	return max;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> height(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	height[n] = 0;

	cout << maxRect(height);
}