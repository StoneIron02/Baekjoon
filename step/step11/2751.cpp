#include <iostream>
using namespace std;

class PQ {
public:
	PQ(int n) {
		arr = new int[n];
		arr[size++] = 0;
	}
	void insert(int x) {
		arr[size++] = x;
		upHeap(size - 1);
	}
	int removeMin() {
		int result = arr[1];
		arr[1] = arr[size - 1];
		size--;
		downHeap(1);
		return result;
	}
private:
	int* arr;
	int size = 0;
	void upHeap(int curIndex) {
		int parentIndex = curIndex / 2;
		if (curIndex == 1) return;
		if (arr[parentIndex] > arr[curIndex]) {
			arr[0] = arr[curIndex];
			arr[curIndex] = arr[parentIndex];
			arr[parentIndex] = arr[0];
			upHeap(parentIndex);
		}
	}
	void downHeap(int curIndex) {
		int leftIndex = curIndex * 2;
		int rightIndex = curIndex * 2 + 1;
		int childIndex;
		if (size - 1 < leftIndex) {
			return;
		}
		else if (size - 1 == leftIndex) {
			childIndex = leftIndex;
		}
		else {
			if (arr[leftIndex] < arr[rightIndex])
				childIndex = leftIndex;
			else
				childIndex = rightIndex;
		}

		if (arr[childIndex] < arr[curIndex]) {
			arr[0] = arr[curIndex];
			arr[curIndex] = arr[childIndex];
			arr[childIndex] = arr[0];
			downHeap(childIndex);
		}
	}
};

int main() {
	int n;
	cin >> n;
	PQ pq = PQ(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.insert(num);
	}
	for (int i = 0; i < n; i++) {
		cout << pq.removeMin() << endl;
	}
}