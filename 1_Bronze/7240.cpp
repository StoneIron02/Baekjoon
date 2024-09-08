#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, S;
  cin >> N >> S;
  int curSpeed = 0;
  while (N--) {
    if (curSpeed > S) {
      curSpeed--;
    }
    int speed;
    cin >> speed;
    curSpeed += speed;
  }
  cout << curSpeed;
}