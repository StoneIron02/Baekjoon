#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int x;
    cin >> x;
    int target = x - 1;
    if ((i - target) & 1) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
