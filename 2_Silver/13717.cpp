#include <iostream>

using namespace std;

int cnt[70];
string name[70];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int sum = 0;
  int maxIdx = 0;
  for (int i = 0; i < N; i++) {
    string str;
    cin >> str;
    name[i] = str;
    int k, m;
    cin >> k >> m;
    while (m >= k) {
      cnt[i]++;
      m -= k - 2;
    }
    sum += cnt[i];
    if (cnt[maxIdx] < cnt[i]) {
      maxIdx = i;
    }
  }

  cout << sum << "\n";
  cout << name[maxIdx];
}