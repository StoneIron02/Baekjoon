#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Queue {
public:
	Queue(int capacity) : capacity(capacity) {
		arr = new T[capacity];
		f = r = 0;
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
			// QueueFull
			return;
		}
		arr[r] = data;
		r = (r + 1) % capacity;
		n++;
	}
	T pop() {
		if (size() == 0) {
			// QueueEmpty
			return -1;
		}
		T data = arr[f];
		f = (f + 1) % capacity;
		n--;
		return data;
	}
	T front() {
		if (size() == 0) {
			// QueueEmpty
			return -1;
		}
		return arr[f];
	}
	T back() {
		if (size() == 0) {
			// QueueEmpty
			return -1;
		}
		return arr[r - 1];
	}
private:
	int n;
	int f, r;
	int capacity;
	T* arr;
};

int main() {
	cin.tie(NULL);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	Queue<int> queue = Queue<int>(n);
	for (int i = 1; i <= n; i++) {
		queue.push(i);
	}
	while (queue.size() > 1) {
		queue.pop();
		queue.push(queue.pop());
	}
	cout << queue.pop();
}