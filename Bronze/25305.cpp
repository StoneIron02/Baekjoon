#include <iostream>
#include <vector>
using namespace std;

class PQ {
public:
	PQ() {
		arr.push_back(0);
	}
	void insert(int x) {
		arr.push_back(x);
		upHeap(arr.size() - 1);
	}
	int removeMax() {
		int result = arr[1];
		arr[1] = arr[arr.size() - 1];
		arr.pop_back();
		downHeap(1);
		return result;
	}
private:
	vector<int> arr;
	void upHeap(int curIndex) {
		if (curIndex == 1) return;
		int parentIndex = curIndex / 2;
		if (arr[parentIndex] < arr[curIndex]) {
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
		if (arr.size() - 1 < leftIndex) {
			return;
		}
		else if (arr.size() - 1 == leftIndex) {
			childIndex = leftIndex;
		}
		else {
			if (arr[leftIndex] > arr[rightIndex])
				childIndex = leftIndex;
			else
				childIndex = rightIndex;
		}

		if (arr[childIndex] > arr[curIndex]) {
			arr[0] = arr[curIndex];
			arr[curIndex] = arr[childIndex];
			arr[childIndex] = arr[0];
			downHeap(childIndex);
		}
	}
};

int main() {
	int n, k;
	cin >> n >> k;
	PQ pq = PQ();
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.insert(num);
	}
	for (int i = 0; i < k - 1; i++) {
		pq.removeMax();
	}
	cout << pq.removeMax();
}