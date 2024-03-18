#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int d;
string first;

int visit[1000];
vector<int> edges[1000];
map<string, int> id;
map<int, string> words;

void BFS() {
  queue<int> q;
  string maxWord = first;
  int s = id[first];
  visit[s] = true;
  q.push(s);

  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    if (maxWord.size() < words[u].size()) {
      maxWord = words[u];
    }

    for (auto& v : edges[u]) {
      if (!visit[v]) {
        visit[v] = true;
        q.push(v);
      }
    }
  }
  cout << maxWord;
}

int main() {
  cin.tie(nullptr);
  cout.tie(nullptr);
  ios_base::sync_with_stdio(false);

  cin >> d >> first;
  for (int i = 0; i < d; i++) {
    string str;
    cin >> str;
    id.insert({str, i});
    words.insert({i, str});
  }

  for (auto& [word, u] : id) {
    for (char j = 0; j < 26; j++) {
      // begin
      string beginStr;
      beginStr += j + 'a';
      beginStr.append(word);
      if (id.find(beginStr) != id.end()) {
        auto& v = id[beginStr];
        edges[u].push_back(v);
      }

      // mid
      for (int i = 0; i < word.size() - 1; i++) {
        // 0 ~ i, i + 1 ~ n - 1
        string str;
        str.append(word.substr(0, i + 1));
        str += j + 'a';
        str.append(word.substr(i + 1));
        if (id.find(str) != id.end()) {
          auto& v = id[str];
          edges[u].push_back(v);
        }
      }

      // end
      string endStr;
      endStr.append(word);
      endStr += j + 'a';
      if (id.find(endStr) != id.end()) {
        auto& v = id[endStr];
        edges[u].push_back(v);
      }
    }
  }

  BFS();
}