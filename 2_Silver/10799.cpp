#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	stack<char> stack;
	string str;
	cin >> str;
	int count = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(')
			stack.push('(');
		else {
			if (str[i - 1] == '(') {
				stack.pop();
				count += stack.size();
			}
			else {
				stack.pop();
				count += 1;
			}
		}
	}
	cout << count;
}
