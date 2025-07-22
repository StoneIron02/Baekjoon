#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  double D;
  int R_H, R_V;

  while (true) {
    cin >> D >> R_H >> R_V;
    if (D == 0 && R_H == 0 && R_V == 0) break;

    double W = (16.0 * D) / sqrt(337);
    double H = (9.0 * D) / sqrt(337);

    double DPI_H = R_H / W;
    double DPI_V = R_V / H;

    cout << fixed << setprecision(2) << "Horizontal DPI: " << DPI_H << "\n" << "Vertical DPI: " << DPI_V << "\n";
  }
}