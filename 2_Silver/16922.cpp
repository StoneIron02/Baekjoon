#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  int letter[4] = {1, 5, 10, 50};

  unordered_set<int> res;
  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N - i; ++j) {
      for (int k = 0; k <= N - i - j; ++k) {
        int l = N - i - j - k;
        int sum = i * letter[0] + j * letter[1] + k * letter[2] + l * letter[3];
        res.insert(sum);
      }
    }
  }

  cout << res.size() << "\n";
}