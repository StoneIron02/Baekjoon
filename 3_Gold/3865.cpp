#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

int visit[1000];
vector<int> edges[1000];
map<string, int> nameToId;

int BFS(int s) {
  queue<int> q;
  visit[s] = true;
  q.push(s);

  int cnt = 0;
  while (!q.empty()) {
    auto top = q.front();
    q.pop();
    if (edges[top].empty()) {
      cnt++;
      continue;
    }
    for (auto v : edges[top]) {
      if (!visit[v]) {
        visit[v] = true;
        q.push(v);
      }
    }
  }
  return cnt;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    cin.ignore();

    nameToId.clear();
    for (int i = 0; i < 1000; i++) {
      visit[i] = false;
      edges[i].clear();
    }

    int id = 0;
    string start;
    for (int i = 0; i < n; i++) {
      string name;
      getline(cin, name, ':');
      if (id == 0) start = name;
      if (nameToId.find(name) == nameToId.end()) {
        nameToId.insert({name, id});
        id++;
      }
      string names;
      getline(cin, names, '.');

      istringstream iss(names);
      string token;
      while (getline(iss, token, ',')) {
        if (nameToId.find(token) != nameToId.end()) {
          edges[nameToId[name]].push_back(nameToId[token]);
        } else {
          nameToId.insert({token, id});
          id++;
          edges[nameToId[name]].push_back(nameToId[token]);
        }
      }
      cin.ignore();
    }

    cout << BFS(nameToId[start]) << "\n";
  }
}