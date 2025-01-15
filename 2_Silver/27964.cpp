#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

string P = "Cheese";

bool ends_with(const string& str) {
  for (int i = 0; i < P.size(); i++) {
    if (str[i] != P[i])
      return false;
  }
  return true;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  unordered_set<string> set;
  reverse(P.begin(), P.end());
  while (N--) {
    string str;
    cin >> str;
    reverse(str.begin(), str.end());
    if (ends_with(str)) set.insert(str);
  }
  if (set.size() >= 4) cout << "yummy";
  else cout << "sad";
}