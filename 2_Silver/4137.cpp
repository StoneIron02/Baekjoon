#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

char charToInt(char ch) {
  if (ch >= '0' && ch <= '9') return ch;
  if (ch >= 'A' && ch <= 'C') return '2';
  if (ch >= 'D' && ch <= 'F') return '3';
  if (ch >= 'G' && ch <= 'I') return '4';
  if (ch >= 'J' && ch <= 'L') return '5';
  if (ch >= 'M' && ch <= 'O') return '6';
  if (ch >= 'P' && ch <= 'S') return '7';
  if (ch >= 'T' && ch <= 'V') return '8';
  if (ch >= 'W' && ch <= 'Y') return '9';
  return ' ';
}

string convert(const string& s) {
  string number;
  for (char ch : s) {
    if (ch == '-') continue;
    if (isdigit(ch)) number += ch;
    else if (isalpha(ch)) number += charToInt(ch);
    if (number.size() == 7) break;
  }
  return number.substr(0, 3) + '-' + number.substr(3, 4);
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  unordered_map<string, int> cnt;
  vector<string> arr;

  string str;
  for (int i = 0; i < n; ++i) {
    cin >> str;
    string convertd = convert(str);
    cnt[convertd]++;
  }

  for (const auto& entry : cnt) {
    if (entry.second > 1) {
      arr.push_back(entry.first);
    }
  }

  if (arr.empty()) {
    cout << "No duplicates." << endl;
  } else {
    sort(arr.begin(), arr.end());
    for (const string& num : arr) {
      cout << num << " " << cnt[num] << endl;
    }
  }
}
