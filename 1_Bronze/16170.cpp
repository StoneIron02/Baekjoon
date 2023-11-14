#include <iostream>
#include <ctime>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    time_t timer = time(nullptr);
    tm* t = gmtime(&timer);

    cout << (t->tm_year + 1900) << "\n";
    cout << (t->tm_mon + 1) << "\n";
    cout << (t->tm_mday) << "\n";
}