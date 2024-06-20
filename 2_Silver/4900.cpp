#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

string digit0 = "063";
string digit1 = "010";
string digit2 = "093";
string digit3 = "079";
string digit4 = "106";
string digit5 = "103";
string digit6 = "119";
string digit7 = "011";
string digit8 = "127";
string digit9 = "107";

unordered_map<string, int> digitToNum = {
    {digit0, 0},
    {digit1, 1},
    {digit2, 2},
    {digit3, 3},
    {digit4, 4},
    {digit5, 5},
    {digit6, 6},
    {digit7, 7},
    {digit8, 8},
    {digit9, 9},
};
unordered_map<int, string> numToDigit = {
    {0, digit0},
    {1, digit1},
    {2, digit2},
    {3, digit3},
    {4, digit4},
    {5, digit5},
    {6, digit6},
    {7, digit7},
    {8, digit8},
    {9, digit9},
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (string s; cin >> s && s != "BYE";) {
    s.pop_back(); s[s.find('+')] = ' ';
    stringstream in(s);
    string s1, s2; in >> s1 >> s2;
    int n1 = 0, n2 = 0;
    for (int i = 0; i < s1.size(); i += 3) {
      string d = s1.substr(i, 3);
      int n = digitToNum[d];
      n1 *= 10;
      n1 += n;
    }
    for (int i = 0; i < s2.size(); i += 3) {
      string d = s2.substr(i, 3);
      int n = digitToNum[d];
      n2 *= 10;
      n2 += n;
    }
    int res = n1 + n2;
    string resStr = to_string(res);
    string result;
    for (char c : resStr) {
      result += numToDigit[c - '0'];
    }
    cout << s1 << "+" << s2 << "=" << result << "\n";
  }
}