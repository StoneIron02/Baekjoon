#include <iostream>
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
	Stack<int> stack1 = Stack<int>(n);
	Stack<int> stack2 = Stack<int>(n);
	Stack<int> result = Stack<int>(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		stack1.push(num);
	}
	for (int i = 0; i < n; i++) {
		int num = stack1.pop();
		while (stack2.size() > 0 && num >= stack2.top())
			stack2.pop();
		result.push(stack2.top());
		stack2.push(num);
	}
	for (int i = 0; i < n; i++) {
		cout << result.pop() << " ";
	}
}