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
	int n;
	cin >> n;
	Stack<int> stack = Stack<int>(100000);
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			stack.push(x);
		}
		else if (command == "pop") {
			cout << stack.pop() << "\n";
		}
		else if (command == "top") {
			cout << stack.top() << "\n";
		}
		else if (command == "size") {
			cout << stack.size() << "\n";
		}
		else if (command == "empty") {
			cout << stack.empty() << "\n";
		}
	}
}