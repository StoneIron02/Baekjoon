#include <iostream>
#include <vector>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  int K;
  cin >> N >> K;
  vector<int> result;
  int fK = (K % 10);
  int f2K = (2 * K % 10);
  for (int i = 1; i <= N; i++) {
    int fi = (i % 10);
    if (fi != fK && fi != f2K) {
      result.push_back(i);
    }
  }

  cout << result.size() << "\n";
  for (int i : result) {
    cout << i << " ";
  }
}