#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, w, h, l;
  cin >> n >> w >> h >> l;
  int n1 = w / l;
  int n2 = h / l;
  int nn = n1 * n2;
  cout << min(nn, n);
}