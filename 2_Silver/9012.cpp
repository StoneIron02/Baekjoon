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
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string str;
		cin >> str;
		Stack<char> stack = Stack<char>(str.size());
		bool empty = false;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(')
				stack.push('(');
			else {
				if (stack.size() == 0) {
					empty = true;
					break;
				}
				stack.pop();
			}
		}
		if (stack.size() == 0 && !empty)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}