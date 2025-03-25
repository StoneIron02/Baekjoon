#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) {
      cin >> words[i];
    }

    sort(words.begin(), words.end(), [](const string& l, const string& r) {
      if (l == r) return false;

      if (r.find(l) == 0) return true;
      if (l.find(r) == 0) return false;

      for (size_t i = 0; i < min(l.size(), r.size()); i++) {
        if (l[i] == r[i]) continue;

        if (l[i] == '-') return false;
        if (r[i] == '-') return true;

        if (tolower(l[i]) != tolower(r[i])) return tolower(l[i]) < tolower(r[i]);

        return l[i] < r[i];
      }
      return l.size() < r.size();
    });

    for (const string &word : words) {
      cout << word << '\n';
    }
  }
}