#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    cout << "Distances: ";
    for (int i = 0; i < a.size(); i++) {
      if (a[i] <= b[i]) {
        cout << (b[i] - a[i]) << " ";
      } else {
        cout << (b[i] + 26 - a[i]) << " ";
      }
    }
    cout << "\n";
  }
}