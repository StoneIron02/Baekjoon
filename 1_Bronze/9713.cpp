#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    int k = (N + 1) / 2;
    cout << k * k << "\n";
  }
}
