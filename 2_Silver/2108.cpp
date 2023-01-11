#include <iostream>
#include <vector>
#include <cmath>
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
	int removeMin() {
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
		if (arr.size() - 1 < leftIndex) {
			return;
		}
		else if (arr.size() - 1 == leftIndex) {
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
	if (n == 1) {
		int num;
		cin >> num;
		cout << num << "\n";
		cout << num << "\n";
		cout << num << "\n";
		cout << 0 << "\n";
		return 0;
	}

	PQ pq = PQ();
	int sum = 0;
	int* arr = new int[8002];
	for (int i = -4000; i <= 4000; i++) {
		arr[i + 4001] = 0;
	}

	// input & exp
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		pq.insert(num);
		sum += num;
		arr[num + 4001]++;
	}
	int exp = round((double)sum / n);
	cout << exp << "\n";

	// max, min, mid
	int min = pq.removeMin();
	for (int i = 1; i < n - 1; i++) {
		int num = pq.removeMin();
		if (i == n / 2)
			cout << num << "\n";
	}
	int max = pq.removeMin();

	// freq
	int countMaxIndex1 = -4001, countMaxIndex2 = -4001;
	for (int i = 4000; i >= -4000; i--) {
		if (arr[countMaxIndex1 + 4001] <= arr[i + 4001]) {
			countMaxIndex2 = countMaxIndex1;
			countMaxIndex1 = i;
		}
	}
	if (arr[countMaxIndex1 + 4001] == arr[countMaxIndex2 + 4001])
		cout << countMaxIndex2 << "\n";
	else
		cout << countMaxIndex1 << "\n";

	cout << max - min << "\n";
}