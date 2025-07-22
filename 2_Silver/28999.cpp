#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;
  vector<int> arr(n);
  for (auto& i : arr) {
    cin >> i;
  }

  vector<int> freq(n + 1);
  for (int i = 0; i < q; i++) {
    int l, r;
    cin >> l >> r;
    freq[l - 1]++;
    freq[r]--;
  }

  for (int i = 1; i < n; i++) {
    freq[i] += freq[i - 1];
  }
  freq.pop_back();

  sort(arr.begin(), arr.end(), greater<>());
  sort(freq.begin(), freq.end(), greater<>());

  long long result = 0;
  for (int i = 0; i < n; i++) {
    result += 1LL * arr[i] * freq[i];
  }
  cout << result << '\n';
}