#include <iostream>
using namespace std;

int n;
int s, e;
int matrix[10][10];
long long t;

int Cal(long long curTime, int curPos) {
  if (curTime > t) return 0;
  if (curTime == t) return 1;

  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (matrix[curPos][i] != 0) {
      sum = (sum * 1LL + Cal(curTime + matrix[curPos][i], i)) % 1'000'003;
    }
  }
  return sum;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n;
  cin >> s >> e;
  s--;
  e--;
  cin >> t;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < n; j++) {
      matrix[i][j] = str[j] - '0';
    }
  }

  cout << Cal(0, s);
}