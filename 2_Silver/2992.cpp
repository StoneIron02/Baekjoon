#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string s;
  cin >> s;
  if (ranges::next_permutation(s).found) cout << s;
  else cout << 0;
}
