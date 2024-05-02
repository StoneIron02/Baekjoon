#include <iostream>
using namespace std;

int l[100001];
int r[100001];
long long cnt = 0;

void trav(int curNode) {
  if (l[curNode] != -1) {
    cnt++;
    trav(l[curNode]);
    cnt++;
  }
  if (r[curNode] != -1) {
    cnt++;
    trav(r[curNode]);
    cnt++;
  }
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    l[a] = b;
    r[a] = c;
  }
  trav(1);
  int cur = 1;
  while (r[cur] != -1) {
    cnt--;
    cur = r[cur];
  }
  cout << cnt;
}