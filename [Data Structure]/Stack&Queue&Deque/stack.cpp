#include <iostream>
#include <vector>
using namespace std;

#define NULL -1

template <typename T>
class stack {
public:
	stack<T>() : n(0) {
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		arr[n++] = data;
	}
	T pop() {
		if (size() == 0) {
			// StackEmpty
			return NULL;
		}
		return arr[--n];
	}
	T top() {
		if (size() == 0) {
			// StackEmpty
			return NULL;
		}
		return arr[n - 1];
	}
private:
	int n;
	vector<T> arr;
};
