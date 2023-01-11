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
	int k;
	cin >> k;
	Stack<int> stack = Stack<int>(100000);
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		if (num == 0)
			stack.pop();
		else
			stack.push(num);
	}

	int sum = 0;
	while (stack.size() > 0) {
		sum += stack.pop();
	}
	cout << sum;
}