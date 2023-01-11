#include <iostream>
#include <vector>
using namespace std;

#define NULL -1

template <typename T>
class deque {
public:
	deque() : n(0), f(0), r(0) {
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push_front(T data) {
		f = (f - 1 + arr.capacity()) % arr.capacity();
		arr[f] = data;
		n++;
	}
	void push_back(T data) {
		arr[r] = data;
		r = (r + 1) % arr.capacity();
		n++;
	}
	T pop_front() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[f];
		f = (f + 1) % arr.capacity();
		n--;
		return data;
	}
	T pop_back() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[(r - 1 + arr.capacity()) % arr.capacity()];
		r = (r - 1 + arr.capacity()) % arr.capacity();
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
		return arr[(r - 1 + arr.capacity()) % arr.capacity()];
	}
private:
	int n;
	int f, r;
	vector<T> arr;
};
