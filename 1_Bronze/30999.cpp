#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, M;
  cin >> N >> M;

  int val = M / 2 + 1;
  int res = 0;

  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    int count = 0;
    for (char c : str) {
      if (c == 'O') ++count;
    }

    if (count >= val) {
      ++res;
    }
  }

  cout << res;
}