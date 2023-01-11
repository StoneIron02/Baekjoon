#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	cin >> n;
	stack<int> stack1;
	stack<int> stack2;
	stack<int> result;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		stack1.push(num);
	}
	for (int i = 0; i < n; i++) {
		int num = stack1.top();
		stack1.pop();
		while (!stack2.empty() && num >= stack2.top())
			stack2.pop();
		if (stack2.empty())
			result.push(-1);
		else 
			result.push(stack2.top());
		stack2.push(num);
	}
	for (int i = 0; i < n; i++) {
		cout << result.top() << " ";
		result.pop();
	}
}