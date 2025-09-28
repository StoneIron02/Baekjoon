#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  unordered_map<string, int> mp_point = {
    {"TT", 75}, {"TX", 50}, {"PR", 80},
    {"RT", 30}, {"AP", 25}, {"PX", 60}
  };

  while (true) {
    int W, N;
    cin >> W >> N;
    if (W == 0) break;

    unordered_map<string, int> sum;
    vector<string> order;
    sum.reserve(N * 2);

    for (int i = 0; i < N; ++i) {
      string name, code;
      cin >> name >> code;
      if (!sum.contains(name)) order.push_back(name);
      sum[name] += mp_point[code];
    }

    vector<string> res;
    res.reserve(order.size());
    for (const string& name : order) {
      if (auto it = sum.find(name); it != sum.end() && it->second >= 100) {
        res.push_back(name);
      }
    }

    cout << "Week " << W << " ";
    if (res.empty()) {
      cout << "No phones confiscated\n";
    } else {
      for (int i = 0; i < res.size(); ++i) {
        if (i) cout << ",";
        cout << res[i];
      }
      cout << '\n';
    }
  }
}