#include <iostream>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;
  int fastReady = 9999;
  while (N--) {
    int time, ready;
    cin >> time >> ready;
    if (time <= ready) {
      fastReady = min(fastReady, ready);
    }
  }
  if (fastReady == 9999) fastReady = -1;
  cout << fastReady;
}
