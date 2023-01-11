#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// A -> 0, B -> 1, C -> 2, D -> 3으로 치환하여 2차원 벡터로 저장
int n, k;
unsigned long long origin[4];
struct card {
	char type;
	int num;
	card(char type, int num) : type(type), num(num) {}
};
bool operator<(const card& left, const card& right) {
	return (left.num < right.num);
}
vector<vector<card>> cards(4);

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	for (int i = 0; i < 4; i++) {
		cin >> origin[i];
	}
	for (int i = 0; i < n; i++) {
		char type;
		cin >> type;
		int num;
		cin >> num;
		cards[type - 'A'].push_back(card(type, num)); // 종류별 저장
	}
	// 정렬
	for (vector<card>& eachCards : cards)
		sort(eachCards.begin(), eachCards.end(), less<card>());

	// 카드 추출
	int count = 0;
	while (count < k) {
		// 변화율이 가장 큰 것을 선택
		double maxDelta = -1;
		int type = -1;
		for (int i = 0; i < 4; i++) {
			double delta = cards[i].empty() ? -1 : (cards[i].back().num / (double)origin[i]);
			if (maxDelta < delta) {
				maxDelta = delta;
				type = i;
			}
		}

		// 카드를 뽑고 출력, 기존 카드값에 변화
		origin[type] += cards[type].back().num;
		cout << cards[type].back().type << " " << cards[type].back().num << "\n";
		cards[type].pop_back();
		count++;
	}
}