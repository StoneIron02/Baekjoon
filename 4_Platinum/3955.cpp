#include <iostream>
#include <tuple>

using namespace std;

// kx'+1=cy => -kx'+cy=1 => kx+cy=1

// 확장 유클리드 호제법
tuple<int, int, int> extended_euclidian(int a, int b) {
    int x_1 = 1;
    int y_1 = 0;
    int r_1 = a;
    int x_2 = 0;
    int y_2 = 1;
    int r_2 = b;

    while (r_2 != 0) {
        int q = r_1 / r_2;
        int r_t = r_1 - q * r_2;
        int x_t = x_1 - q * x_2;
        int y_t = y_1 - q * y_2;
        x_1 = x_2;
        y_1 = y_2;
        r_1 = r_2;
        x_2 = x_t;
        y_2 = y_t;
        r_2 = r_t;
    }

    return {x_1, y_1, r_1};
}

int get_result(int k, int c) {
    tuple<int, int, int> exeu = extended_euclidian(k, c);
    int x = get<0>(exeu);
    int y = get<1>(exeu);
    int r = get<2>(exeu);

    // 서로소가 아니면 수식을 만족하지 않음.
    if (r != 1)
        return -1;

    // 각 수의 범위 조정.
    while (y <= 0 || x >= 0) {
        y += k;
        x -= c;
    }

    // 답이 제한 범위를 초과하면 안 됨.
    if (y > 1'000'000'000)
        return -1;

    return y;
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int k, c;
        cin >> k >> c;

        int result = get_result(k, c);
        if (result == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << result << "\n";
    }
}