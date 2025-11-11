#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

string cal(string s) {
  string vowels = "aeiou";
  for (auto &c : s) c = tolower(c);
  for (int i = s.size() - 1; i >= 0; i--) {
    if (vowels.find(s[i]) != string::npos)
      return s.substr(i);
  }
  return s;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  cin.ignore();
  for (int v = 0; v < N; v++) {
    vector<string> str(4);
    for (int i = 0; i < 4; i++) getline(cin, str[i]);
    vector<string> syl(4);
    for (int i = 0; i < 4; i++) {
      stringstream ss(str[i]);
      string word, last;
      while (ss >> word) last = word;
      syl[i] = cal(last);
    }
    bool a = syl[0] == syl[1] && syl[1] == syl[2] && syl[2] == syl[3];
    bool b = syl[0] == syl[1] && syl[2] == syl[3];
    bool c = syl[0] == syl[2] && syl[1] == syl[3];
    bool d = syl[0] == syl[3] && syl[1] == syl[2];
    if (a) cout << "perfect\n";
    else if (b) cout << "even\n";
    else if (c) cout << "cross\n";
    else if (d) cout << "shell\n";
    else cout << "free\n";
  }
}
