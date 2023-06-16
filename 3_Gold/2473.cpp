#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    int potion[n];
    for (int i = 0; i < n; i++)
        cin >> potion[i];
    sort(potion, potion + n);

    long long minAbs = INT64_MAX;
    vector<int> selectIndex;
    for (int i = 0; i < n; i++) { //select potion[i]
        int j = 0;
        int k = n - 1;
        if (j == i)
            j++;
        if (k == i)
            k--;
        while (j < k) {
            long long num = (long long)potion[i] + potion[j] + potion[k];
            if (minAbs > abs(num)) {
                minAbs = abs(num);
                selectIndex.clear();
                selectIndex.push_back(i);
                selectIndex.push_back(j);
                selectIndex.push_back(k);
            }

            if (num > 0)
                k--;
            else
                j++;

            if (j == i)
                j++;
            if (k == i)
                k--;
        }
    }

    sort(selectIndex.begin(), selectIndex.end());
    for (auto item : selectIndex)
        cout << potion[item] << " ";
}