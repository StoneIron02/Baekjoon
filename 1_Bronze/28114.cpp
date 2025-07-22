#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  struct Member {
    int solved;
    int year;
    string name;
  };

  vector<Member> arr(3);
  for (int i = 0; i < 3; ++i) {
    cin >> arr[i].solved >> arr[i].year >> arr[i].name;
  }

  vector<int> years;
  for (int i = 0; i < 3; ++i) {
    years.push_back(arr[i].year % 100);
  }
  sort(years.begin(), years.end());

  for (int y : years) {
    if (y < 10) cout << '0';
    cout << y;
  }
  cout << '\n';

  sort(arr.begin(), arr.end(), [](const Member &a, const Member &b) {
    return a.solved > b.solved;
  });

  for (int i = 0; i < 3; ++i) {
    cout << arr[i].name[0];
  }
  cout << "\n";
}