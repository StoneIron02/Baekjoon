#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Color {
  int R;
  int G;
  int B;
  Color() : R(0), G(0), B(0) {}
  Color(int R, int G, int B) : R(R), G(G), B(B) {}
};

double cal(const Color& a, const Color& b) {
  return sqrt((a.R - b.R) * (a.R - b.R) + (a.G - b.G) * (a.G - b.G) + (a.B - b.B) * (a.B - b.B));
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    vector<Color> arr(N);
    for (auto& c : arr) {
      cin >> c.R >> c.G >> c.B;
    }

    double max_val = -1;
    vector<pair<int, int>> res;
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        double val = cal(arr[i], arr[j]);
        if (val > max_val) {
          max_val = val;
          res.clear();
          res.emplace_back(i, j);
        } else if (val == max_val) {
          res.emplace_back(i, j);
        }
      }
    }

    cout << "Data Set " << t << ":\n";
    for (auto& p : res) {
      cout << p.first + 1 << " " << p.second + 1 << "\n";
    }
  }
}