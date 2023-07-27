#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    double weight, height;
    cin >> weight >> height;

    double BMI = weight / (height * height);
    if (BMI > 25)
        cout << "Overweight";
    else if (BMI < 18.5)
        cout << "Underweight";
    else
        cout << "Normal weight";
}