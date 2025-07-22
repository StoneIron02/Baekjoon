#include <iostream>
#include <map>

using namespace std;

struct comp {
  bool operator()(const string& a, const string& b) const {
    if (a.size() != b.size()) {
      return a.size() < b.size();
    }
    return a < b;
  }
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  map<string, int, comp> mp;

  for (int i = 0; i < n; i++) {
    string name;
    int cnt;
    cin >> name >> cnt;
    mp[name] += cnt;
  }

  for (const auto& p : mp) {
    cout << p.first << " " << p.second << "\n";
  }
}