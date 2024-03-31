#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int angle = 0;
  for (int i = 0; i < 10; i++) {
    int n;
    cin >> n;
    if (n == 1) {
      angle = (angle + 90) % 360;
    } else if (n == 2) {
      angle = (angle + 180) % 360;
    } else {
      angle = (angle + 270) % 360;
    }
  }

  if (angle == 0) {
    cout << "N";
  } else if (angle == 90) {
    cout << "E";
  } else if (angle == 180) {
    cout << "S";
  } else {
    cout << "W";
  }
}