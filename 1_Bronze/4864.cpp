#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  vector<int> days;
  int n;
  while (cin >> n && n != 0) {
    days.push_back(n);
  }

  int max_days = 0;
  for (int d : days) {
    if (d > max_days) max_days = d;
  }

  vector<int> gold_sum(max_days + 1, 0);

  int total_coins = 0, current_gold = 1, count = 0;
  for (int day = 1; day <= max_days; ++day) {
    total_coins += current_gold;
    gold_sum[day] = total_coins;
    count++;

    if (count == current_gold) {
      count = 0;
      current_gold++;
    }
  }

  for (int d : days) {
    cout << d << " " << gold_sum[d] << "\n";
  }
}