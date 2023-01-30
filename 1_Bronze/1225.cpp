#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    string aStr, bStr;
    cin >> aStr >> bStr;
    long long sum = 0;
    for (char aChar : aStr) {
        for (char bChar : bStr) {
            int a = aChar - '0';
            int b = bChar - '0';
            sum += a * b;
        }
    }
    cout << sum;
}