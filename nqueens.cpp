#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> results;

bool isValid(vector<int> &board, int n) {
    for (int i = 0; i < n * n; i++) {
        if (board[i] == 0) continue;

        int row = i / n, col = i % n;

        for (int j = i + 1; j < n * n; j++) {
            if (board[j] == 0) continue;

            int row1 = j / n, col1 = j % n;

            if (row == row1 || col == col1 || abs(row - row1) == abs(col - col1)) {
                return false;
            }
        }
    }
    return true;
}

void generate(vector<int> &board, int n, int i, vector<int> &queens) {
    if (i == n) {
        if (isValid(board, n)) {
            results.push_back(board);
        }
        return;
    }

    int currentQueen = queens[i];
    for (int j = 0; j < n * n; j++) {
        if (board[j] == 0) {
            board[j] = currentQueen;
            generate(board, n, i + 1, queens);
            board[j] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> queens(n);
    for (int i = 0; i < n; i++) {
        queens[i] = i + 1;
    }

    vector<int> board(n * n, 0);
    generate(board, n, 0, queens);

    for (auto &config : results) {
        for (int i = 0; i < n * n; i++) {
            cout << config[i] << ' ';
            if (i % n == n - 1) cout << '\n';
        }
        cout << '\n';
    }

    cout << results.size() << '\n';

    return 0;
}