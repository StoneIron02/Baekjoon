#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int M, A, B;
  while (cin >> M >> A >> B) {
    if (M == 0 && A == 0 && B == 0) break;
    double t1 = (double)M / A;
    double t2 = (double)M / B;
    double diff = (t1 - t2) * 3600;
    int total = round(diff);
    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = total % 60;
    cout << h << ":";
    if (m < 10) cout << "0";
    cout << m << ":";
    if (s < 10) cout << "0";
    cout << s << "\n";
  }
}
