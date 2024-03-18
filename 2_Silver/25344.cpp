#include <iostream>
#include <numeric>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  unsigned long long l;
  cin >> l;
  n--;
  while (n--) {
    unsigned long long num;
    cin >> num;
    l = lcm(l, num);
  }
  cout << l;
}