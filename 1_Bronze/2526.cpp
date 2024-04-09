#include <iostream>
using namespace std;

int n, p;
int visit[1001];
int num[1001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> n >> p;
  int i = 0;
  int v = n;
  while (true) {
    if (visit[v]) {
      cout << i - num[v];
      exit(0);
    }
    visit[v] = true;
    num[v] = i;
    v = (v * n) % p;
    i++;
  }

}