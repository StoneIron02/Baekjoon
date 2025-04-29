#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  unordered_set<string> us;
  while (N--) {
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    us.insert(str);
  }
  cout << us.size();
}
