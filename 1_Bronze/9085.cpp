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
    int sum = 0;
    while (N--) {
      int num;
      cin >> num;
      sum += num;
    }
    cout << sum << "\n";
  }
}