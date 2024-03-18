#include <iostream>
#include <numeric>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  int l = 1;
  while (n--) {
    int num;
    cin >> num;
    l = lcm(l, num);
  }
  cout << l;
}