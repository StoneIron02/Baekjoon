#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int wc, hc, ws, hs;
  cin >> wc >> hc >> ws >> hs;
  if (ws <= wc - 2 && hs <= hc - 2) cout << 1;
  else cout << 0;
}