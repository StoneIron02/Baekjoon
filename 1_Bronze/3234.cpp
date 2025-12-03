#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int X, Y;
  cin >> X >> Y;
  int K;
  cin >> K;
  string str;
  cin >> str;

  int x = 0, y = 0;
  vector<int> res;
  auto check = [&](int a, int b){
    return abs(a - X) <= 1 && abs(b - Y) <= 1;
  };

  if (check(x, y)) res.push_back(0);

  for (int i = 0; i < K; ++i){
    char c = str[i];
    if (c == 'I') x++;
    else if (c == 'S') y++;
    else if (c == 'Z') x--;
    else y--;

    if (check(x, y)) res.push_back(i + 1);
  }

  if (res.empty()){
    cout << -1;
  } else {
    for (int v : res) cout << v << "\n";
  }
}