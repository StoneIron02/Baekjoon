#include <iostream>
#include <tuple>

using namespace std;

tuple<long long, long long, long long> extended_euclidian(long long a, long long b) {
    long long x_1 = 1;
    long long y_1 = 0;
    long long r_1 = a;
    long long x_2 = 0;
    long long y_2 = 1;
    long long r_2 = b;

    while (r_2 != 0) {
        long long q = r_1 / r_2;
        long long r_t = r_1 - q * r_2;
        long long x_t = x_1 - q * x_2;
        long long y_t = y_1 - q * y_2;
        x_1 = x_2;
        y_1 = y_2;
        r_1 = r_2;
        x_2 = x_t;
        y_2 = y_t;
        r_2 = r_t;
    }

    return {x_1, y_1, r_1};
}

long long get_inv(long long n, long long a) {
    tuple<long long, long long, long long> exeu = extended_euclidian(n, a);
    long long y = get<1>(exeu);
    long long r = get<2>(exeu);
    if (r != 1) {
        return -1;
    } else {
        return (y + n) % n;
    }
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, a;
    cin >> n >> a;
    long long add_inv = n - a;
    long long mul_inv = get_inv(n, a);
    cout << add_inv << " " << mul_inv;
}