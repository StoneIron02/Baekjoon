#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int s, a, b;
  cin >> s >> a >> b;
  int curHeight = a;
  int curValue = 250;
  while (curHeight < s) {
    curHeight += b;
    curValue += 100;
  }
  cout << curValue;
}
