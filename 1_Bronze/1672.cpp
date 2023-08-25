#include <iostream>

using namespace std;

int arr[4][4] = {{0, 2, 0, 1}, {2, 1, 3, 0}, {0, 3, 2, 1}, {1, 0, 1, 3}};

int char_to_int(char c) {
    if (c == 'A')
        return 0;
    else if (c == 'G')
        return 1;
    else if (c == 'C')
        return 2;
    else
        return 3;
}

char int_to_char(int n) {
    if (n == 0)
        return 'A';
    else if (n == 1)
        return 'G';
    else if (n == 2)
        return 'C';
    else
        return 'T';
}

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string input;
    cin >> input;

    char last = input[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        char before = input[i];
        int num_last = char_to_int(last);
        int num_before = char_to_int(before);
        int num_result = arr[num_before][num_last];
        char result = int_to_char(num_result);
        last = result;
    }
    cout << last;
}