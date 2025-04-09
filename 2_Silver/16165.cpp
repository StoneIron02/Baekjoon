#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  unordered_map<string, vector<string>> teamToMember;
  unordered_map<string, string> memberToTeam;

  for (int i = 0; i < N; ++i) {
    string teamName;
    int memberCount;
    cin >> teamName >> memberCount;

    vector<string> members;
    for (int j = 0; j < memberCount; ++j) {
      string member;
      cin >> member;
      members.push_back(member);
      memberToTeam[member] = teamName;
    }
    teamToMember[teamName] = members;
  }

  for (int i = 0; i < M; ++i) {
    string cmd;
    int type;
    cin >> cmd >> type;

    if (type == 0) {
      vector<string> members = teamToMember[cmd];
      sort(members.begin(), members.end());
      for (auto& member : members) {
        cout << member << endl;
      }
    } else {
      cout << memberToTeam[cmd] << endl;
    }
  }
}