#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;
  if (A <= B || A > 2 * B) {
    cout << "NO\n";
    return 0;
  }

  int K = A - B;
  cout << "YES\n" << K << "\n";

  vector<int> arr(K, 1);
  if (K > 0) arr[0] += B - K;
  for (int i = 0; i < K; i++) {
    int num = arr[i];
    string str;
    for (int j = 0; j < num; j++) {
      str += "ab";
    }
    str += "a";
    cout << str << "\n";
  }
}
