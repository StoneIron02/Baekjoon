#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    char c;
    cin >> c;
    for (int i = 0; i < num; i++) {
      for (int j = 0; j < i + 1; j++) {
        cout << (char)(((c - 'A' + i) % 26) + 'A');
      }
      cout << "\n";
    }
    cout << "\n";
  }
}