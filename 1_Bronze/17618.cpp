#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    string iStr = to_string(i);
    int sum = 0;
    for (char c : iStr) {
      sum += c - '0';
    }
    if (i % sum == 0) cnt++;
  }
  cout << cnt;
}