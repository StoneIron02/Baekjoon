#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  cin >> str;
  for (char& c : str) {
    int n = c - 'A';
    n = (n - 3 + 26) % 26;
    c = (char)(n + 'A');
  }
  cout << str;
}