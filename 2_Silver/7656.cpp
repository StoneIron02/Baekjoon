#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  getline(cin, str);

  vector<string> substr;
  string cur;

  for (char c : str) {
    if (c >= 'A' && c <= 'Z') {
      cur.clear();
    }
    cur += c;
    if (c == '.' || c == '?') {
      substr.push_back(cur);
    }
  }

  for (const auto& sub : substr) {
    if (sub.starts_with("What is") && sub.back() == '?') {
      cout << "Forty-two" << sub.substr(4, sub.size() - 5) << ".\n";
    }
  }
  
}
