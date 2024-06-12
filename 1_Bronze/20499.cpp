#include <iostream>
#include <sstream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string strK, strD, strA;
  int k, d, a;
  getline(cin, strK, '/');
  getline(cin, strD, '/');
  getline(cin, strA);
  k = stoi(strK);
  d = stoi(strD);
  a = stoi(strA);
  if (k + a < d || d == 0) {
    cout << "hasu";
  } else {
    cout << "gosu";
  }
}