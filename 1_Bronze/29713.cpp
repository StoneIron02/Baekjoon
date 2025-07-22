#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  string str;
  cin >> N >> str;

  string check = "BRONZESILVER";
  unordered_map<char, int> mp;
  for (char c : check)
    mp[c]++;

  unordered_map<char, int> available;
  for (char c : str)
    available[c]++;

  int res = 1e9;
  for (auto& [ch, count] : mp) {
    res = min(res, available[ch] / count);
  }

  cout << res;
}