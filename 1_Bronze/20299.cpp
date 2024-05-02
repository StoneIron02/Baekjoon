#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, k, l;
  cin >> n >> k >> l;
  int cnt = 0;
  vector<int> result;
  while (n--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a >= l && b >= l && c >= l && a + b + c >= k) {
      cnt++;
      result.push_back(a);
      result.push_back(b);
      result.push_back(c);
    }
  }
  cout << cnt << "\n";
  for (auto i : result) {
    cout << i << " ";
  }
}