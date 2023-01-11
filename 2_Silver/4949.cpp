#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Stack {
public:
	Stack(int capacity) : capacity(capacity) {
		arr = new T[capacity];
		n = 0;
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		if (size() == capacity) {
			// StackFull
			return;
		}
		arr[n++] = data;
	}
	int pop() {
		if (size() == 0) {
			// StackEmpty
			return -1;
		}
		return arr[--n];
	}
	int top() {
		if (size() == 0) {
			// StackEmpty
			return -1;
		}
		return arr[n - 1];
	}
private:
	int n;
	int capacity;
	T* arr;
};

int main() {
	while (true) {
		string str;
		getline(cin, str);
		if (str == ".") break;
		Stack<char> stack = Stack<char>(str.size());
		bool correct = true;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(')
				stack.push(str[j]);
			else if (str[j] == '[')
				stack.push('[');
			else if (str[j] == ')') {
				if (stack.size() == 0) {
					correct = false;
					break;
				}
				if (stack.pop() != '(') {
					correct = false;
					break;
				}				
			}
			else if (str[j] == ']') {
				if (stack.size() == 0) {
					correct = false;
					break;
				}
				if (stack.pop() != '[') {
					correct = false;
					break;
				}
			}
		}

		if (stack.size() == 0 && correct)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}