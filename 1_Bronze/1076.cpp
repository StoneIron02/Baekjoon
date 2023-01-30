#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<string, int> value;
    value.insert({ "black", 0 });
    value.insert({ "brown", 1 });
    value.insert({ "red", 2 });
    value.insert({ "orange", 3 });
    value.insert({ "yellow", 4 });
    value.insert({ "green", 5 });
    value.insert({ "blue", 6 });
    value.insert({ "violet", 7 });
    value.insert({ "grey", 8 });
    value.insert({ "white", 9 });

    string a, b, c;
    cin >> a >> b >> c;
    long long sum = 0;
    sum += value[a];
    sum *= 10;
    sum += value[b];
    for (int i = 0; i < value[c]; i++)
        sum *= 10;
    cout << sum;
}