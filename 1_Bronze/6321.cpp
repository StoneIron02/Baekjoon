#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    cout << "String #" << i << "\n";
    for (char c : str) {
      if (c == 'Z') cout << 'A';
      else cout << (char)(c + 1);
    }
    cout << "\n\n";
  }
}