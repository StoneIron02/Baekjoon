#include <iostream>
#include <cstring>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string T, P;
  cin >> T >> P;
  auto result = strstr(T.c_str(), P.c_str());
  if (result != NULL) cout << 1;
  else cout << 0;
}