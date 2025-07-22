#include <iostream>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  string str;
  cin >> N >> str >> K;

  bool flag = (str == "annyong");
  int closest;

  for (int offset = 0; ; ++offset) {
    int up = K + offset;
    int down = K - offset;

    if (up <= N && ((up % 2 == 1) == flag)) {
      closest = up;
      break;
    }
    if (down >= 1 && ((down % 2 == 1) == flag)) {
      closest = down;
      break;
    }
  }

  cout << closest;
}