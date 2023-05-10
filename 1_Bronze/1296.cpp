#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string lime;
    cin >> lime;
    int limeCount[26];
    for (int & i : limeCount) {
        i = 0;
    }
    for (char c : lime) {
        limeCount[c - 'A']++;
    }

    int n;
    cin >> n;
    int max = -1;
    set<string> maxTeam;
    for (int i = 0; i < n; i++) {
        string team;
        cin >> team;
        int teamCount[26];
        for (int & j : teamCount) {
            j = 0;
        }
        for (char c : team) {
            teamCount[c - 'A']++;
        }
        teamCount['L'-'A'] += limeCount['L'-'A'];
        teamCount['O'-'A'] += limeCount['O'-'A'];
        teamCount['V'-'A'] += limeCount['V'-'A'];
        teamCount['E'-'A'] += limeCount['E'-'A'];
        int result = ((teamCount['L'-'A']+teamCount['O'-'A']) * (teamCount['L'-'A']+teamCount['V'-'A'])
                * (teamCount['L'-'A']+teamCount['E'-'A']) * (teamCount['O'-'A']+teamCount['V'-'A'])
                * (teamCount['O'-'A']+teamCount['E'-'A']) * (teamCount['V'-'A']+teamCount['E'-'A'])) % 100;
        if (result > max) {
            maxTeam.clear();
            max = result;
        }
        if (result == max) {
            maxTeam.insert(team);
        }
    }

    cout << *maxTeam.begin();
}