#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  cin.ignore();
  while (n--) {
    string str;
    getline(cin, str);
    int idx = 0;
    int cnt = 0;
    for (char c : str) {
      if (idx == 0 && (c == 'P' || c == 'p')) {
        idx++;
      }
      else if (idx == 1 && (c == 'L' || c == 'l')) {
        idx++;
      }
      else if (idx == 2 && (c == 'U' || c == 'u')) {
        idx = 0;
        cnt++;
      }
    }
    cout << cnt << "\n";
  }
}