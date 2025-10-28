#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  string str;
  cin >> N >> str;

  int r_cnt = 0, b_cnt = 0;
  for (int i = 0; i < N; ++i) {
    if (str[i] == 'R' && (i == 0 || str[i - 1] != 'R')) ++r_cnt;
    if (str[i] == 'B' && (i == 0 || str[i - 1] != 'B')) ++b_cnt;
  }

  cout << min(r_cnt, b_cnt) + 1;
}
