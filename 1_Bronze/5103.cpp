#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    string code;
    cin >> code;
    if (code == "#") break;

    int M, S;
    cin >> M >> S;
    int T;
    cin >> T;
    while (T--) {
      char type;
      int x;
      cin >> type >> x;
      if (type == 'S') {
        int sold = min(S, x);
        S -= sold;
      }
      else {
        S += x;
        if (S > M)
          S = M;
      }
    }

    cout << code << " " << S << "\n";
  }
}
