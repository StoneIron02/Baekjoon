#include <iostream>
#include <vector>

using namespace std;

bool check(const string& s1, const string& s2) {
  int l = min(s1.size(), s2.size());

  for (int len = 1; len <= l; len++) {
    if (s1.compare(s1.size() - len, len, s2, 0, len) == 0) {
      return true;
    }
  }

  for (int len = 1; len <= l; len++) {
    if (s2.compare(s2.size() - len, len, s1, 0, len) == 0) {
      return true;
    }
  }

  return false;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<string> arr(N);
  for (auto& i : arr) {
    cin >> i;
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (check(arr[i], arr[j])) cnt++;
    }
  }
  cout << cnt;
}