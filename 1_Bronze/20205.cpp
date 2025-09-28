#include <iostream>
using namespace std;

int arr[10][10];

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < N; ++i) {
    for (int t = 0; t < K; ++t) {
      for (int j = 0; j < N; ++j) {
        for (int s = 0; s < K; ++s) {
          cout << arr[i][j] << " ";
        }
      }
      cout << "\n";
    }
  }
}