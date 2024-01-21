#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int cnt = 0;
  string x;
  cin >> x;
  while (x.size() > 1) {
    cnt++;
    int sum = 0;
    for (char c : x) {
      sum += c - '0';
    }
    x = to_string(sum);
  }
  cout << cnt << "\n";
  cout << ((x == "3" || x == "6" || x == "9") ? "YES" : "NO");
}