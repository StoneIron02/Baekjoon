#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int n, k;
pair<int, int> gem[300'000]; // value, weight
multiset<int> knapsack;

struct compare {
    bool operator()(pair<int, int> gem1, pair<int, int> gem2) {
        if (gem1.first == gem2.first)
            return gem1.second < gem2.second;
        return gem1.first > gem2.first;
    }
};

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int weight, value;
        cin >> weight >> value;
        gem[i] = {value, weight};
    }
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        knapsack.insert(c);
    }

    sort(gem, gem + n, compare());

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        auto weight = gem[i].second;
        auto value = gem[i].first;
        auto pos = knapsack.lower_bound(weight);
        if (pos == knapsack.end()) { // no pick up
            continue;
        }
        sum += value;
        knapsack.erase(pos);
    }
    cout << sum;
}