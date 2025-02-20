#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  string str;
  cin >> str;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0 && str[i] != 'I') {
      cnt++;
    }
    if (i % 2 == 1 && str[i] != 'O') {
      cnt++;
    }
  }
  cout << cnt;
}