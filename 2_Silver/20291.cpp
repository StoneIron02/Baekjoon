#include <iostream>
#include <map>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;

  map<string, int> cnt;
  for (int i = 0; i < N; ++i) {
    string name;
    cin >> name;
    string ext = name.substr(name.find('.') + 1);
    ++cnt[ext];
  }

  for (auto& [name, n] : cnt) {
    cout << name << " " << n << "\n";
  }
}