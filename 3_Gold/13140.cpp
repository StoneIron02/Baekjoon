#include <iostream>
#include <iomanip>
using namespace std;

int n;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n;
  for (int d = 0; d <= 9; d++) {
    for (int e = 0; e <= 9; e++) {
      if (e == d) continue;
      for (int h = 1; h <= 9; h++) {
        if (h == d) continue;
        if (h == e) continue;
        for (int l = 0; l <= 9; l++) {
          if (l == d) continue;
          if (l == e) continue;
          if (l == h) continue;
          for (int o = 0; o <= 9; o++) {
            if (o == d) continue;
            if (o == e) continue;
            if (o == h) continue;
            if (o == l) continue;
            for (int r = 0; r <= 9; r++) {
              if (r == d) continue;
              if (r == e) continue;
              if (r == h) continue;
              if (r == l) continue;
              if (r == o) continue;
              for (int w = 1; w <= 9; w++) {
                if (w == d) continue;
                if (w == e) continue;
                if (w == h) continue;
                if (w == l) continue;
                if (w == o) continue;
                if (w == r) continue;

                int hello = h * 10000 + e * 1000 + l * 100 + l * 10 + o;
                int world = w * 10000 + o * 1000 + r * 100 + l * 10 + d;
                if (hello + world == n) {
                  cout << " " << setw(6) << right << hello << "\n";
                  cout << "+" << setw(6) << right << world << "\n";
                  cout << "-------\n";
                  cout << " " << setw(6) << right << n;
                  exit(0);
                }
              }
            }
          }
        }
      }
    }
  }

  cout << "No Answer";
}