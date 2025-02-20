#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int Z;
  cin >> Z;

  while (Z--) {
    int n;
    cin >> n;
    string path;
    cin >> path;

    int x = 0, y = 0;

    for (char dir : path) {
      if (dir == 'N') y++;
      else if (dir == 'S') y--;
      else if (dir == 'E') x++;
      else if (dir == 'W') x--;
    }

    cout << abs(x) + abs(y) << endl;
  }
}