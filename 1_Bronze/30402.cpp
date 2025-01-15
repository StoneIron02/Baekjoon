#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      char c;
      cin >> c;
      if (c == 'w') {
        cout << "chunbae";
        return 0;
      }
      if (c == 'b') {
        cout << "nabi";
        return 0;
      }
      if (c == 'g') {
        cout << "yeongcheol";
        return 0;
      }
    }
  }
}