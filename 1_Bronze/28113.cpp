#include <iostream>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, A, B;
  cin >> N >> A >> B;

  int subway_time = max(N, B);
  if (A < subway_time)
    cout << "Bus" << endl;
  else if (A > subway_time)
    cout << "Subway" << endl;
  else
    cout << "Anything" << endl;
}