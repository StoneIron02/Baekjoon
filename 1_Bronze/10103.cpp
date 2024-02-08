#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int score[2] {100, 100};
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      score[1] -= a;
    } else if (a < b) {
      score[0] -= b;
    }
  }
  cout << score[0] << "\n" << score[1];
}