#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int sum = 0;
  while (true) {
    int num;
    cin >> num;
    if (num == -1) break;
    sum += num;
  }
  cout << sum;
}