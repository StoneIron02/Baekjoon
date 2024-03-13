#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> numbers(n);
    for (int i = 0; i < n; i++) {
      cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    bool result = true;
    for (int i = 0; i < n - 1; i++) {
      bool flag = true;
      for (int j = 0; j < numbers[i].size(); j++) {
        if (numbers[i][j] != numbers[i + 1][j]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        result = false;
        break;
      }
    }
    if (result) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}