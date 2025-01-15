#include <iostream>
#include <vector>
#include <sstream>
#include <climits>

using namespace std;

pair<int, int> pos[100];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  int min_x = INT_MAX, min_y = INT_MAX;
  int max_x = INT_MIN, max_y = INT_MIN;

  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;

    stringstream ss(str);
    string x_str, y_str;
    getline(ss, x_str, ',');
    getline(ss, y_str, ',');

    int x = stoi(x_str);
    int y = stoi(y_str);

    min_x = min(min_x, x);
    min_y = min(min_y, y);
    max_x = max(max_x, x);
    max_y = max(max_y, y);
  }

  cout << (min_x - 1) << "," << (min_y - 1) << endl;
  cout << (max_x + 1) << "," << (max_y + 1) << endl;
}