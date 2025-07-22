#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int today;
  cin >> today;
  int res = 999999;
  bool flag = false;
  for (int i = 1; i < n; ++i) {
    int val;
    cin >> val;
    if (!flag && val <= today) {
      res = i;
      flag = true;
    }
  }

  if (res == 999999) {
    cout << "infinity";
  } else {
    cout << res;
  }
}