#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define NULL 0

template <typename T>
class priority_queue {
public:
	priority_queue() {
		isMinHeap = true;
		arr.push_back(NULL);
	}
	priority_queue(bool isMinHeap) : isMinHeap(isMinHeap) {
		arr.push_back(NULL);
	}
	int size() {
		return (arr.size() - 1);
	}
	bool empty() {
		return (size() == 0);
	}
	void push(T data) {
		arr.push_back(data);
		upHeap(size());
	}
	T pop() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		T result = arr[1];
		arr[1] = arr[size()];
		arr.pop_back();
		downHeap(1);
		return result;
	}
	T top() {
		if (size() == 0) {
			// QueueEmpty
			return NULL;
		}
		return arr[1];
	}
private:
	bool isMinHeap;
	vector<T> arr;
	void swap(int index1, int index2) {
		arr[0] = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = arr[0];
	}
	void upHeap(int curIndex) {
		if (curIndex == 1) return;
		int parentIndex = curIndex / 2;
		if (isMinHeap) {
			if (arr[curIndex] < arr[parentIndex]) {
				swap(curIndex, parentIndex);
				upHeap(parentIndex);
			}
		}
		else {
			if (arr[parentIndex] < arr[curIndex]) {
				swap(curIndex, parentIndex);
				upHeap(parentIndex);
			}
		}
	}
	void downHeap(int curIndex) {
		int leftIndex = curIndex * 2;
		int rightIndex = curIndex * 2 + 1;
		int childIndex;
		if (size() < leftIndex) {
			return;
		}
		else if (size() == leftIndex) {
			childIndex = leftIndex;
		}
		else {
			if (isMinHeap) {
				if (arr[leftIndex] < arr[rightIndex])
					childIndex = leftIndex;
				else
					childIndex = rightIndex;
			}
			else {
				if (arr[rightIndex] < arr[leftIndex])
					childIndex = leftIndex;
				else
					childIndex = rightIndex;
			}
		}
		if (isMinHeap) {
			if (arr[childIndex] < arr[curIndex]) {
				swap(curIndex, childIndex);
				downHeap(childIndex);
			}
		}
		else {
			if (arr[curIndex] < arr[childIndex]) {
				swap(curIndex, childIndex);
				downHeap(childIndex);
			}
		}
	}
};

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	priority_queue<int> min;
	priority_queue<int> max = priority_queue<int>(false);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (min.size() == 0 && max.size() == 0) {
			max.push(num);
			cout << max.top() << "\n";
			continue;
		}
		else if (min.size() == 0 || max.size() == 0) {
			max.push(num);
			min.push(max.pop());
			cout << max.top() << "\n";
			continue;
		}
		else {
			if (num < min.top())
				max.push(num);
			else
				min.push(num);

			while ((min.size() - max.size()) > 0)
				max.push(min.pop());
			while ((max.size() - min.size()) > 1)
				min.push(max.pop());

			cout << max.top() << "\n";
		}
	}
}