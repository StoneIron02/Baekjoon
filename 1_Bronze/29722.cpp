#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string s;
  int N;
  cin >> s >> N;

  int yyyy = stoi(s.substr(0, 4));
  int mm   = stoi(s.substr(5, 2));
  int dd   = stoi(s.substr(8, 2));
  int daystamp = yyyy * 360 + (mm - 1) * 30 + (dd - 1);

  daystamp += N;
  int y = daystamp / 360;
  daystamp %= 360;
  int m = daystamp / 30;
  int d = daystamp % 30;

  cout << setw(4) << setfill('0') << y << "-";
  cout << setw(2) << setfill('0') << (m + 1) << "-";
  cout << setw(2) << setfill('0') << (d + 1) << "\n";
}