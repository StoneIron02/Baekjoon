#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int c;
vector<int> house(200'000);

/*
 * 간격에 대한 투 포인터를 이용.
 * 각 시도에서 최소간격과 최대간격의 중간 간격에 대해 설치할 수 있는 공유기의 개수를 알아봄.
 * 공유기의 개수가 c 이상이면 가능한 해 중 하나이므로 최대간격을 비교하여 최댓값 갱신,
 *      이후 간격 범위를 중간 간격보다 큰 범위로 좁혀서 다시 알아봄.
 * 공유기의 개수가 c 미만이면 가능하지 않은 해이므로 최댓값은 갱신하지 않고,
 *      이후 간격 범위를 중간 간격보다 작은 범위로 좁혀서 다시 알아봄.
 * */

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> house[i];

    sort(house.begin(), house.begin() + n);

    int min_length = 1;
    int max_length = house[n - 1] - house[0];

    int result = min_length;

    while (min_length <= max_length) {
        int length = (min_length + max_length) / 2;
        int prev_house = house[0];

        int num_router = 1;

        for (int i = 1; i < n; i++) {
            int cur_length = house[i] - prev_house;
            if (cur_length >= length) {
                num_router++;
                prev_house = house[i];
            }
        }

        if (num_router >= c) {
            result = max(result, length);
            min_length = length + 1;
        } else {
            max_length = length - 1;
        }
    }

    cout << result;
}