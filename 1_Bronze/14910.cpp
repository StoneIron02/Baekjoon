#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int prev, cur;
  bool isGood = true;

  if (!(cin >> prev)) {
    cout << "Good\n";
    return 0;
  }

  while (cin >> cur) {
    if (prev > cur) {
      isGood = false;
      break;
    }
    prev = cur;
  }

  cout << (isGood ? "Good\n" : "Bad\n");
}
