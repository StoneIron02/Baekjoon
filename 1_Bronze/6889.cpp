#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<string> adjectives(n);
  vector<string> nouns(m);

  for (int i = 0; i < n; ++i) {
    cin >> adjectives[i];
  }

  for (int i = 0; i < m; ++i) {
    cin >> nouns[i];
  }

  for (const auto& adj : adjectives) {
    for (const auto& noun : nouns) {
      cout << adj << " as " << noun << '\n';
    }
  }
}