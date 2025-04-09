#include <iostream>
#include <map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  while (cin >> N && N != 0) {
    map<int, int> gold_cnt;
    map<int, int> total_cnt;

    for (int i = 0; i < N; ++i) {
      int Y;
      string S, M;
      cin >> Y >> S >> M;

      total_cnt[Y]++;
      if (M == "Gold") {
        gold_cnt[Y]++;
      }
    }

    int max_gold_year = 9999, max_total_year = 9999;
    int max_gold = -1, max_total = -1;

    for (auto &entry : gold_cnt) {
      int Y = entry.first;
      int cnt = entry.second;
      if (cnt > max_gold || (cnt == max_gold && Y < max_gold_year)) {
        max_gold = cnt;
        max_gold_year = Y;
      }
    }

    for (auto &entry : total_cnt) {
      int Y = entry.first;
      int cnt = entry.second;
      if (cnt > max_total || (cnt == max_total && Y < max_total_year)) {
        max_total = cnt;
        max_total_year = Y;
      }
    }

    cout << max_gold_year << " " << max_total_year << endl;
  }

}