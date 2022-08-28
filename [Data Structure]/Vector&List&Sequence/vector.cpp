#include <iostream>
using namespace std;

#define NULL -1

template <typename T>
class vector {
public:
	vector() : n(0), capacity(1), arr(new T[capacity]) {
	}
	~vector() {
		delete[] arr;
	}
	T operator[](int index) {
		return arr[index];
	}
	int size() {
		return n;
	}
	bool empty() {
		return (size() == 0);
	}
	T at(int index) {
		if (index < 0 || index >= size()) {
			// OutOfIndex
			return NULL;
		}
		return arr[index];
	}
	void set(int index, T data) {
		if (index < 0 || index >= size()) {
			// OutOfIndex
			return;
		}
		arr[index] = data;
	}
	void insert(int index, T data) {
		if (index < 0 || index > size()) {
			// OutOfIndex
			return;
		}
		if (size() == capacity) {
			reserve(capacity * 2);
		}
		for (int i = n - 1; i >= index; i--) {
			arr[i + 1] = arr[i];
		}
		arr[index] = data;
		n++;
	}
	void erase(int index) {
		if (empty()) {
			// VectorEmpty
			return;
		}
		if (index < 0 || index >= size()) {
			// OutOfIndex
			return;
		}
		for (int i = index; i <= n - 2; i++) {
			arr[i] = arr[i + 1];
		}
		n--;
	}
private:
	int n;
	int capacity;
	T* arr;
	void reserve(int newSize) {
		if (newSize <= capacity)
			return;
		T* newArr = new T[newSize];
		for (int i = 0; i < n; i++) {
			newArr[i] = arr[i];
		}
		capacity = newSize;
		if (arr != 0)
			delete[] arr;
		arr = newArr;
	}
};
