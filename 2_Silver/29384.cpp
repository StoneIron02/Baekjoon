#include <iostream>
#include <queue>
using namespace std;

int endtimes[1001];
int menus[1001];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  int now = 0;
  queue<int> que;

  for (int i = 1; i <= k; ++i) {
    int start_time, duration, menu;
    cin >> start_time >> duration >> menu;

    while (!que.empty() && endtimes[que.front()] <= start_time) {
      if (menus[que.front()] == 1) ++m;
      ++n;
      que.pop();
    }

    if (menu == 0) {
      if (n > 0) {
        cout << "Yes\n";
        --n;
        que.push(i);
      } else {
        cout << "No\n";
      }
    } else {
      if (n > 0 && m > 0) {
        cout << "Yes\n";
        --n;
        --m;
        que.push(i);
      } else {
        cout << "No\n";
      }
    }

    now = start_time;
    endtimes[i] = now + duration;
    menus[i] = menu;
  }
}