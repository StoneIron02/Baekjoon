#include <iostream>
using namespace std;

int arr[100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int N, D;
    cin >> N >> D;
    if (N == 0 && D == 0) break;

    for (int i = 0; i < N; ++i) {
      arr[i] = 0;
    }
    for (int d = 0; d < D; ++d) {
      for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 1) arr[i]++;
      }
    }

    bool found = false;
    for (int i = 0; i < N; ++i) {
      if (arr[i] == D) {
        found = true;
        break;
      }
    }

    cout << (found ? "yes" : "no") << "\n";
  }
}
