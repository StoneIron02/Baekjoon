#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  string str;
  long long n;
  while (cin >> str >> n) {
    cout << str << " " << n << " = ";
    int len = str.size();
    vector<long long> fact(11, 1);
    for (int i = 1; i <= 10; ++i) fact[i] = fact[i-1] * i;
    if (n > fact[len]) {
      cout << "No permutation\n";
      continue;
    }
    n--;
    string ans;
    vector<char> chars(str.begin(), str.end());
    for (int i = len - 1; i >= 0; i--) {
      long long idx = n / fact[i];
      n %= fact[i];
      ans.push_back(chars[idx]);
      chars.erase(chars.begin() + idx);
    }
    cout << ans << "\n";
  }
}
