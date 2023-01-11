#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<unsigned long long> weight(30);
vector<unsigned long long> sumLeft;
vector<unsigned long long> sumRight;

void calSum(int curIndex, int endIndex, int curSum, vector<unsigned long long>& v) {
	if (curSum > c) return; // �Ұ����� ��� ����

	if (curIndex > endIndex) { // �� case�� �� ����� ������ vector�� push
		v.push_back(curSum);
		return;
	}

	// �ش� �ε����� ������ �ִ� ���
	calSum(curIndex + 1, endIndex, curSum + weight[curIndex], v);

	// �ش� �ε����� ������ ���� �ʴ� ���
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

	// left�� �� ��쿡 ���� right�� ������ �� ������ ����� ���� ���
	sort(sumRight.begin(), sumRight.end());
	long long correct = 0;
	for (unsigned long long curSum : sumLeft) {
		unsigned long long bound = c - curSum;
		correct += upper_bound(sumRight.begin(), sumRight.end(), bound) - sumRight.begin();
	}
	cout << correct;
}