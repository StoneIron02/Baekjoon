#include <iostream>
#include <queue>
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

int pushNum = 1;

int main() {
	int n;
	cin >> n;
	bool correct = true;
	Stack<int> stack = Stack<int>(n);
	queue<char> queue;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		while (pushNum <= num) {
			stack.push(pushNum++);
			queue.push('+');
		}
		int checkNum = stack.pop();
		queue.push('-');
		if (checkNum != num) {
			correct = false;
			break;
		}
	}

	if (correct) {
		while (queue.size() > 0) {
			cout << queue.front() << "\n";
			queue.pop();
		}
	}
	else {
		cout << "NO\n";
	}
}