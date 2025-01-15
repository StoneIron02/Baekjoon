#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string str;
  int cntRe = 0, cntPt = 0, cntCc = 0, cntEa = 0, cntTb = 0, cntCm = 0, cntEx = 0, cntTotal = 0;
  while (cin >> str) {
    if (str == "Re") cntRe++;
    else if (str == "Pt") cntPt++;
    else if (str == "Cc") cntCc++;
    else if (str == "Ea") cntEa++;
    else if (str == "Tb") cntTb++;
    else if (str == "Cm") cntCm++;
    else if (str == "Ex") cntEx++;
    cntTotal++;
  }
  cout << fixed << setprecision(2) << "Re " << cntRe << " " << (1.0 * cntRe / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Pt " << cntPt << " " << (1.0 * cntPt / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Cc " << cntCc << " " << (1.0 * cntCc / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Ea " << cntEa << " " << (1.0 * cntEa / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Tb " << cntTb << " " << (1.0 * cntTb / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Cm " << cntCm << " " << (1.0 * cntCm / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Ex " << cntEx << " " << (1.0 * cntEx / cntTotal) << "\n";
  cout << fixed << setprecision(2) << "Total " << cntTotal << " " << (1.0 * cntTotal / cntTotal) << "\n";
}