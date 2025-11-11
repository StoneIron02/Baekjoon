#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int f, r;
    cin >> f;
    if (f == 0) break;
    cin >> r;

    vector<int> front(f), rear(r);
    for (int i = 0; i < f; ++i) cin >> front[i];
    for (int i = 0; i < r; ++i) cin >> rear[i];

    vector<double> arr;
    for (int i = 0; i < f; ++i)
      for (int j = 0; j < r; ++j)
        arr.push_back((double)rear[j] / front[i]);

    sort(arr.begin(), arr.end());

    double max_speed = 0;
    for (size_t i = 1; i < arr.size(); ++i)
      max_speed = max(max_speed, arr[i] / arr[i - 1]);

    cout << fixed << setprecision(2) << max_speed << endl;
  }
}
