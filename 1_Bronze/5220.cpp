#include <iostream>

using namespace std;

int check(int num) {
  int count = 0;
  while (num) {
    count += num & 1;
    num >>= 1;
  }
  return count;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int N, b;
    cin >> N >> b;

    int cnt = check(N);
    if ((cnt % 2 == 0 && b == 0) || (cnt % 2 == 1 && b == 1)) {
      cout << "Valid\n";
    } else {
      cout << "Corrupt\n";
    }
  }
}