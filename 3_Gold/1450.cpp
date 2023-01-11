#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<unsigned long long> weight(30);
vector<unsigned long long> sumLeft;
vector<unsigned long long> sumRight;

void calSum(int curIndex, int endIndex, int curSum, vector<unsigned long long>& v) {
	if (curSum > c) return; // 불가능한 경우 제거

	if (curIndex > endIndex) { // 각 case의 합 계산이 끝나면 vector에 push
		v.push_back(curSum);
		return;
	}

	// 해당 인덱스의 물건을 넣는 경우
	calSum(curIndex + 1, endIndex, curSum + weight[curIndex], v);

	// 해당 인덱스의 물건을 넣지 않는 경우
	calSum(curIndex + 1, endIndex, curSum, v);
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> weight[i];

	calSum(0, n / 2 - 1, 0, sumLeft); // left
	calSum(n / 2, n - 1, 0, sumRight); // right

	// left의 각 경우에 대해 right를 더했을 때 가능한 경우의 수를 계산
	sort(sumRight.begin(), sumRight.end());
	long long correct = 0;
	for (unsigned long long curSum : sumLeft) {
		unsigned long long bound = c - curSum;
		correct += upper_bound(sumRight.begin(), sumRight.end(), bound) - sumRight.begin();
	}
	cout << correct;
}