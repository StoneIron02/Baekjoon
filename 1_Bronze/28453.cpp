#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  while (N--) {
    int M;
    cin >> M;
    if (M == 300) {
      cout << 1 << " ";
    } else if (M >= 275) {
      cout << 2 << " ";
    } else if (M >= 250) {
      cout << 3 << " ";
    } else {
      cout << 4 << " ";
    }
  }
}