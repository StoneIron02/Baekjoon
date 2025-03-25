#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  unordered_map<int, int> mp;
  for (int i = 0; i < N; i++) {
    int num, name;
    cin >> num >> name;
    mp[num] = name;
  }

  int R;
  cin >> R;
  while (R--) {
    int l;
    cin >> l;
    vector<int> arr(l);
    for (int i = 0; i < l; i++) {
      cin >> arr[i];
    }

    vector<int> res;
    bool flag = true;
    for (int i : arr) {
      if (mp.find(i) != mp.end()) {
        res.push_back(mp[i]);
      } else {
        flag = false;
      }
    }

    if (flag) {
      for (int i : res) {
        cout << i << " ";
      }
      cout << endl;
    } else {
      cout << "YOU DIED" << endl;
    }
  }
}