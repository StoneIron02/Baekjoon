#include <iostream>
#include <algorithm>

using namespace std;

int cnt[26];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  string str;
  cin >> str;
  for (char c : str) {
    cnt[c - 'A']++;
  }
  int resRange[5] = {cnt['H' - 'A'], cnt['I' - 'A'], cnt['A' - 'A'], cnt['R' - 'A'], cnt['C' - 'A']};
  cout << *min_element(resRange, resRange + 5);
}