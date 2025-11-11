#include <iostream>
#include <iomanip>
#include <unordered_map>
using namespace std;

struct Info {
  int accepted_count = 0;
  double total_submissions = 0;
  double total_time = 0;
};

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);
  
  int n;
  cin >> n;
  unordered_map<char, Info> problems;
  unordered_map<string, unordered_map<char, pair<int, bool>>> team_data;

  for (int i = 0; i < n; ++i) {
    int time;
    string team;
    char prob, result;
    cin >> time >> team >> prob >> result;
    if (team_data[team][prob].second) continue;
    team_data[team][prob].first++;
    if (result == 'A') {
      team_data[team][prob].second = true;
      problems[prob].accepted_count++;
      problems[prob].total_submissions += team_data[team][prob].first;
      problems[prob].total_time += time;
    }
  }

  cout << fixed << setprecision(2);
  for (char p = 'A'; p <= 'I'; ++p) {
    auto& info = problems[p];
    cout << p << " " << info.accepted_count;
    if (info.accepted_count > 0)
      cout << " " << info.total_submissions / info.accepted_count << " " << info.total_time / info.accepted_count;
    cout << "\n";
  }
}
