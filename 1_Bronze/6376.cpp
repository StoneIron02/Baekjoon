#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cout << "n e" << "\n";
  cout << "- -----------\n";

  double sum = 0.0;
  double factorial = 1.0;

  for (int i = 0; i <= 9; i++) {
    if (i == 0) {
      sum = 1.0;
      cout << i << " 1" << "\n";
    } else if (i == 1) {
      factorial *= i;
      sum += 1.0 / factorial;
      cout << i << " 2" << endl;
    } else if (i == 2) {
      factorial *= i;
      sum += 1.0 / factorial;
      cout << i << " 2.5" << endl;
    } else {
      factorial *= i;
      sum += 1.0 / factorial;
      cout << i << " " << fixed << setprecision(9) << sum << endl;
    }
  }

}