#include <iostream>
#include <string>
using namespace std;

#define NULL -1

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
	int n;
	cin >> n;
	Deque<int> deque = Deque<int>(n);
	for (int i = 0; i < n; i++) {
		string command;
		cin >> command;
		if (command == "push_front") {
			int x;
			cin >> x;
			deque.push_front(x);
		}
		else if (command == "push_back") {
			int x;
			cin >> x;
			deque.push_back(x);
		}
		else if (command == "pop_front") {
			cout << deque.pop_front() << "\n";
		}
		else if (command == "pop_back") {
			cout << deque.pop_back() << "\n";
		}
		else if (command == "size") {
			cout << deque.size() << "\n";
		}
		else if (command == "empty") {
			cout << deque.empty() << "\n";
		}
		else if (command == "front") {
			cout << deque.front() << "\n";
		}
		else if (command == "back") {
			cout << deque.back() << "\n";
		}
	}
}