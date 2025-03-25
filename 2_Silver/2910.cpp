#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, C;
  cin >> N >> C;

  vector<int> arr(N);
  unordered_map<int, int> freq;
  unordered_map<int, int> first;

  for (int i = 0; i < N; ++i) {
    cin >> arr[i];
    freq[arr[i]]++;
    if (first.find(arr[i]) == first.end())
      first[arr[i]] = i;
  }

  sort(arr.begin(), arr.end(), [&](int a, int b) {
    if (freq[a] == freq[b])
      return first[a] < first[b];
    return freq[a] > freq[b];
  });

  for (int num : arr)
    cout << num << " ";
}