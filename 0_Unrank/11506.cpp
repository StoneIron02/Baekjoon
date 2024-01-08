#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  str += 0xEF;
  str += 0xBF;
  str += 0xBD;

  cout << str;
}