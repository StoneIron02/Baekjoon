#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct pos {
	int xOriginal;
	int xChange;
	pos(int xOriginal) : xOriginal(xOriginal) {
	}
	bool isSmallerThan(pos* p) {
		return (xOriginal < p->xOriginal);
	}
	friend ostream& operator<<(ostream& out, pos* p) {
		out << p->xChange;
		return out;
	}
};

template <typename T>
class PQ {
public:
	PQ<T>() {
		arr.push_back(NULL);
	}
	void insert(T data) {
		arr.push_back(data);
		upHeap(arr.size() - 1);
	}
	T removeMin() {
		T result = arr[1];
		arr[1] = arr[arr.size() - 1];
		arr.pop_back();
		downHeap(1);
		return result;
	}
private:
	vector<T> arr;
	void upHeap(int curIndex) {
		if (curIndex == 1) return;
		int parentIndex = curIndex / 2;
		if (arr[curIndex]->isSmallerThan(arr[parentIndex])) {
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
			if (arr[leftIndex]->isSmallerThan(arr[rightIndex]))
				childIndex = leftIndex;
			else
				childIndex = rightIndex;
		}

		if (arr[childIndex]->isSmallerThan(arr[curIndex])) {
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
	PQ<pos*> pq = PQ<pos*>();
	vector<pos*> list;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pos* p = new pos(num);
		list.push_back(p);
		pq.insert(p);
	}

	int count = -1;
	int prev = -1000000001;
	for (int i = 0; i < n; i++) {
		pos* p = pq.removeMin();
		if (prev < p->xOriginal)
			count++;
		p->xChange = count;
		prev = p->xOriginal;
	}

	for (int i = 0; i < n; i++) {
		cout << list[i] << " ";
	}
}