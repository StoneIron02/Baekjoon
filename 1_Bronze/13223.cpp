#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int h1, m1, s1, h2, m2, s2;
  char tmp;

  cin >> h1 >> tmp >> m1 >> tmp >> s1;
  cin >> h2 >> tmp >> m2 >> tmp >> s2;

  int start = h1 * 3600 + m1 * 60 + s1;
  int end = h2 * 3600 + m2 * 60 + s2;

  int diff = end - start;
  if (diff <= 0) diff += 24 * 3600;

  int hh = diff / 3600;
  int mm = (diff % 3600) / 60;
  int ss = diff % 60;

  cout << setfill('0') << setw(2) << hh << ":" << setfill('0') << setw(2) << mm << ":" << setfill('0') << setw(2) << ss << endl;

  return 0;
}