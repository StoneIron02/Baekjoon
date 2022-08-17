#include <iostream>
#include <vector>
using namespace std;

struct position {
	int x;
	int y;
	position(int x, int y) : x(x), y(y) {
	}
	bool isSmallerThan(position* p) {
		if (y == p->y)
			return (x < p->x);
		else
			return (y < p->y);
	}
	friend ostream& operator<<(ostream& out, position* p) {
		out << p->x << " " << p->y;
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
	PQ<position*> pq = PQ<position*>();
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.insert(new position(x, y));
	}

	for (int i = 0; i < n; i++) {
		cout << pq.removeMin() << "\n";
	}
}