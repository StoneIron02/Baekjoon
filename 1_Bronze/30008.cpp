#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  vector<int> G(K);
  for (int i = 0; i < K; ++i)
    cin >> G[i];

  for (int i = 0; i < K; ++i) {
    int P = (G[i] * 100) / N;

    int grade;
    if (P <= 4) grade = 1;
    else if (P <= 11) grade = 2;
    else if (P <= 23) grade = 3;
    else if (P <= 40) grade = 4;
    else if (P <= 60) grade = 5;
    else if (P <= 77) grade = 6;
    else if (P <= 89) grade = 7;
    else if (P <= 96) grade = 8;
    else grade = 9;

    cout << grade << " ";
  }
}