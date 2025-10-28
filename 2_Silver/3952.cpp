#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int P;
  cin >> P;
  cin.ignore();
  while (P--) {
    string str;
    getline(cin, str);
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) cin >> nums[i];
    cin.ignore();

    string res;
    int pos = 0;
    for (int i = 0; i < N; ++i) {
      pos += nums[i];
      while (pos < 0) pos += str.size();
      pos %= str.size();
      res.push_back(str[pos]);
    }
    cout << res << "\n";
  }
}