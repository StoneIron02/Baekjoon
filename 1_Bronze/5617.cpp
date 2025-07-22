#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int a, b, c;
  int total = 0;
  int jik = 0;
  int ye = 0;
  int dun = 0;

  while (cin >> a >> b >> c) {
    int line[3] = {a, b, c};
    sort(line, line + 3);

    if (line[0] + line[1] <= line[2]) {
      cout << total << " " << jik << " " << ye << " " << dun << "\n";
      return 0;
    }

    total++;

    int a2 = line[0] * line[0];
    int b2 = line[1] * line[1];
    int c2 = line[2] * line[2];

    if (a2 + b2 == c2) {
      jik++;
    } else if (a2 + b2 > c2) {
      ye++;
    } else {
      dun++;
    }
  }

  cout << total << " " << jik << " " << ye << " " << dun << "\n";
}