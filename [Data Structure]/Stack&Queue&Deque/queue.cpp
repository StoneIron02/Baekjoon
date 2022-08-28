#include <iostream>
#include <vector>
using namespace std;

#define NULL -1

template <typename T>
class queue {
public:
	queue() : n(0), f(0), r(0) {
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		arr[r] = data;
		r = (r + 1) % arr.capacity();
		n++;
	}
	T pop() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T data = arr[f];
		f = (f + 1) % arr.capacity();
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
