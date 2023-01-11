#include <iostream>
using namespace std;

template <typename T>
class Deque {
public:
	Deque(int capacity) : capacity(capacity) {
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
	void push_front(T data) {
		if (size() == capacity) {
			// QueueFull
			return;
		}
		f = (f - 1) % capacity;
		arr[f] = data;
		n++;
	}
	void push_back(T data) {
		if (size() == capacity) {
			// QueueFull
			return;
		}
		arr[r] = data;
		r = (r + 1) % capacity;
		n++;
	}
	T pop_front() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[f];
		f = (f + 1) % capacity;
		n--;
		return data;
	}
	T pop_back() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[(r - 1) % capacity];
		r = (r - 1) % capacity;
		n--;
		return data;
	}
	T front() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		return arr[f];
	}
	T back() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		return arr[(r - 1) % capacity];
	}
private:
	int n;
	int f, r;
	int capacity;
	T* arr;
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int count = 0;
	Deque<int> deque = Deque<int>(n);
	for (int i = 1; i <= n; i++) {
		deque.push_back(i);
	}
	while (deque.size() > (n - m)) {
		int num;
		cin >> num;
		int leftCount = 0;
		while (deque.front() != num) {
			deque.push_back(deque.pop_front());
			leftCount++;
		}
		int rightCount = deque.size() - leftCount;
		count += (leftCount > rightCount ? rightCount : leftCount);
		deque.pop_front();
	}
	cout << count;
}