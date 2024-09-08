#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int sum = 0;
  int m = 100;
  for (int i = 0; i < 3; i++) {
    int num;
    cin >> num;
    sum += num;
    m = min(m, num);
  }
  cout << (sum - m);
}