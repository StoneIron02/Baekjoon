#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  char c;
  cin >> c;
  string str = "ILOVEYONSEI";
  int sum = 0;
  for (char ch : str) {
    sum += min(abs(c - ch), abs(ch - c));
    c = ch;
  }
  cout << sum;
}