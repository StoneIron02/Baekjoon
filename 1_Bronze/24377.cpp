#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr(4);
vector<int> missing;
vector<int> positions;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  for (int i = 0; i < 4; ++i) {
    cin >> arr[i];
    if (arr[i] == 0) {
      positions.push_back(i + 1);
    }
  }

  for (int i = 1; i <= 4; ++i) {
    if (find(arr.begin(), arr.end(), i) == arr.end()) {
      missing.push_back(i);
    }
  }

  if (missing.size() == 0) {
    cout << arr[0] << " " << arr[1] << endl;
  } else if (missing.size() == 1) {
    cout << positions[0] << " " << missing[0] << endl;
  } else {
    sort(missing.begin(), missing.end());
    cout << missing[0] << " " << missing[1] << endl;
  }
}