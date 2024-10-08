#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int a, b, c;
  cin >> a >> b >> c;
  if (c >= a && c < b) {
    cout << 1;
  } else {
    cout << 0;
  }
}
