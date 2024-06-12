#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  unordered_map<string, string> LtoS;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string S, L;
    cin >> S >> L;
    LtoS.insert({L, S});
  }
  string str;
  cin >> str;
  string result;
  for (char c : str) {
    string st;
    st += c;
    result += LtoS[st];
  }
  int s, e;
  cin >> s >> e;
  cout << result.substr(s - 1, e - s + 1);
}