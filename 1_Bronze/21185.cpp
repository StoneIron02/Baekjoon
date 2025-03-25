#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  if (N % 2 == 0) {
    if ((N / 2) % 2 == 1) cout << "Odd";
    else cout << "Even";
  } else {
    cout << "Either";
  }
}