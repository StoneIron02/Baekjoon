#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int M = -1;

    // □□□□ test
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i][j + 3];
            M = max(M, sum);
        }
    }

    // □ test
    // □
    // □
    // □
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m; j++) {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 3][j];
            M = max(M, sum);
        }
    }

    // □□ test
    // □□
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1];
            M = max(M, sum);
        }
    }

    // □ test
    // □
    // □□
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 2][j] + matrix[i + 2][j + 1];
            M = max(M, sum);
        }
    }

    // □□□ test
    // □
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i][j + 1] + matrix[i][j + 2];
            M = max(M, sum);
        }
    }

    // □□ test
    //  □
    //  □
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i + 1][j + 1] + matrix[i + 2][j + 1];
            M = max(M, sum);
        }
    }

    //   □ test
    // □□□
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 1][j + 2] + matrix[i][j + 2];
            M = max(M, sum);
        }
    }

    //  □ test
    //  □
    // □□
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j + 1] + matrix[i + 1][j + 1] + matrix[i + 2][j] + matrix[i + 2][j + 1];
            M = max(M, sum);
        }
    }

    // □□□ test
    //   □
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 2];
            M = max(M, sum);
        }
    }

    // □□ test
    // □
    // □
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 2][j];
            M = max(M, sum);
        }
    }

    // □ test
    // □□□
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 1][j + 2] + matrix[i][j];
            M = max(M, sum);
        }
    }

    // □ test
    // □□
    //  □
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 2][j + 1];
            M = max(M, sum);
        }
    }

    //  □ test
    // □□
    // □
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 2][j];
            M = max(M, sum);
        }
    }

    // □□ test
    //  □□
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i + 1][j + 1] + matrix[i + 1][j + 2];
            M = max(M, sum);
        }
    }

    //  □□ test
    // □□
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 1] + matrix[i][j + 2];
            M = max(M, sum);
        }
    }

    // □ test
    // □□
    // □
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j] + matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 2][j];
            M = max(M, sum);
        }
    }

    //  □ test
    // □□
    //  □
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            int sum = matrix[i][j + 1] + matrix[i + 1][j] + matrix[i + 1][j + 1] + matrix[i + 2][j + 1];
            M = max(M, sum);
        }
    }

    // □□□ test
    //  □
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i][j] + matrix[i][j + 1] + matrix[i][j + 2] + matrix[i + 1][j + 1];
            M = max(M, sum);
        }
    }

    //  □ test
    // □□□
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = matrix[i + 1][j] + matrix[i][j + 1] + matrix[i + 1][j + 2] + matrix[i + 1][j + 1];
            M = max(M, sum);
        }
    }

    cout << M;
}