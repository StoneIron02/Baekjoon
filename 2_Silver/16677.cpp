#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  string m;
  cin >> m;
  int N;
  cin >> N;

  string best = "";
  long long best_g = -1, best_add = 1;

  for (int i = 0; i < N; ++i) {
    string w;
    long long g;
    cin >> w >> g;

    int p = 0;
    for (char c : w) {
      if (p < m.size() && c == m[p])
        p++;
    }
    if (p != m.size())
      continue;

    long long add = w.size() - m.size();
    if (add <= 0)
      continue;

    if (best.empty() || g * best_add > best_g * add) {
      best = w;
      best_g = g;
      best_add = add;
    }
  }

  if (best.empty())
    cout << "No Jam";
  else
    cout << best;
}
