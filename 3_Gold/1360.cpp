#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

vector<tuple<int, string>> states;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  states.emplace_back(0, "");
  int N;
  cin >> N;
  while (N--) {
    string cmd;
    cin >> cmd;
    if (cmd == "type") {
      char c;
      cin >> c;
      int cur_time;
      cin >> cur_time;
      states.emplace_back(cur_time, get<1>(states.back()) + c);
    } else {
      int t;
      cin >> t;
      int cur_time;
      cin >> cur_time;
      int undo_start_time = cur_time - t;
      int i;
      for (i = states.size() - 1; get<0>(states[i]) > 0 && get<0>(states[i]) >= undo_start_time; i--) {
      }
      states.emplace_back(cur_time, get<1>(states[i]));
    }
  }
  cout << get<1>(states.back());
}
