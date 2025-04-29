#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int S, N, M;
  cin >> S >> N >> M;
  int size = 0, capacity = S;
  for (int i = 0; i < N + M; i++) {
    bool b;
    cin >> b;
    if (b) {
      if (size == capacity) capacity *= 2;
      size++;
    } else {
      size--;
    }
  }
  cout << capacity;
}
