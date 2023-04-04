#include <iostream>
#include <iomanip>
#include <string>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    map<string, double> score;
    score.insert({"A+", 4.5});
    score.insert({"A0", 4.0});
    score.insert({"B+", 3.5});
    score.insert({"B0", 3.0});
    score.insert({"C+", 2.5});
    score.insert({"C0", 2.0});
    score.insert({"D+", 1.5});
    score.insert({"D0", 1.0});
    score.insert({"F", 0.0});

    double sumGrade = 0;
    double sumScore = 0;

    for (int i = 0; i < 20; i++) {
        string name;
        double grade;
        string scoreStr;
        cin >> name >> grade >> scoreStr;
        if (scoreStr == "P")
            continue;

        sumGrade += grade;
        sumScore += grade * score[scoreStr];
    }
    double average = sumScore / sumGrade;
    cout << fixed << setprecision(10) << average;
}