#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string a, b;
  cin >> a >> b;

  // min
  for (char& c : a) {
    if (c == '5' || c == '6') {
      c = '5';
    }
  }
  for (char& c : b) {
    if (c == '5' || c == '6') {
      c = '5';
    }
  }
  cout << stoi(a) + stoi(b) << " ";

  // max
  for (char& c : a) {
    if (c == '5' || c == '6') {
      c = '6';
    }
  }
  for (char& c : b) {
    if (c == '5' || c == '6') {
      c = '6';
    }
  }
  cout << stoi(a) + stoi(b) << " ";
}