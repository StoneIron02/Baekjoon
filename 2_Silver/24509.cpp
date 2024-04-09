#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct scores {
  bool award = false;
  int num;
  int score[4];
};

int option = 0;
bool compare(scores& sc1, scores& sc2) {
  if (sc1.score[option] == sc2.score[option]) {
    return sc1.num < sc2.num;
  }
  return sc1.score[option] > sc2.score[option];
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<scores> arr(n + 1);
  for (int i = 1; i <= n; i++) {
    scores sc{};
    cin >> sc.num;
    for (int& j : sc.score) {
      cin >> j;
    }
    arr[i] = sc;
  }

  option = 0;
  for (int t = 0; t < 4; t++) {
    sort(arr.begin() + 1, arr.end(), compare);
    for (int i = 1; i <= n; i++) {
      if (!arr[i].award) {
        cout << arr[i].num << " ";
        arr[i].award = true;
        break;
      }
    }
    option++;
  }
}
