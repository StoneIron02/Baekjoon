#include <iostream>

using namespace std;

int value[3][200];
int cnt[3][101];
int score[200];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> value[j][i];
      cnt[j][value[j][i]]++;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      if (cnt[j][value[j][i]] == 1) {
        score[i] += value[j][i];
      }
    }
    cout << score[i] << "\n";
  }
}