#include <iostream>

using namespace std;

long long cnt = 0;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string str_num = to_string(i);
    for (char c : str_num) {
      if (c == '3' || c == '6' || c == '9')
        cnt++;
    }
  }
  cout << cnt;
}