#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  unordered_map<string, int> m;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    m[str]++;
  }
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    m[str]--;
  }
  for (auto& [str, cnt] : m) {
    if (cnt > 0) {
      cout << str;
      break;
    }
  }
}