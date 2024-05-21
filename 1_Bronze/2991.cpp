#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int p, m, n;
  cin >> p >> m >> n;
  bool aAttack = true, bAttack = true;
  int aLeft = a, bLeft = c;
  int resultP = 0, resultM = 0, resultN = 0;
  for (int i = 1; i < 1000; i++) {
    if (i == p) {
      if (aAttack) resultP++;
      if (bAttack) resultP++;
    }
    if (i == m) {
      if (aAttack) resultM++;
      if (bAttack) resultM++;
    }
    if (i == n) {
      if (aAttack) resultN++;
      if (bAttack) resultN++;
    }
    aLeft--;
    if (aLeft == 0) {
      aAttack = !aAttack;
      aLeft = aAttack ? a : b;
    }
    bLeft--;
    if (bLeft == 0) {
      bAttack = !bAttack;
      bLeft = bAttack ? c : d;
    }
  }
  cout << resultP << "\n" << resultM << "\n" << resultN;
}