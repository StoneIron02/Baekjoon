#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int maxScore[10] = {0, 100, 100, 200, 200, 300, 300, 400, 400, 500};
  bool isHacker = false;

  int sum = 0;
  for (int i = 0; i < 9; i++) {
    int num;
    cin >> num;
    if (num > maxScore[i + 1]) {
      isHacker = true;
    }
    sum += num;
  }
  if (isHacker) {
    cout << "hacker";
  } else if (sum < 100) {
    cout << "none";
  } else {
    cout << "draw";
  }
}