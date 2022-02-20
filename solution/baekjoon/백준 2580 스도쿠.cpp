#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

typedef long long ll;
const ll LL_INF = 10000000000;
const int INF = 1000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

using namespace std;

char input;
int sudoku[9][9];
bool finish = false;

// return 0 when impossible
bool isPossible(int y, int x, int number) {
    bool possible = true;
    
    int ry = y / 3 * 3;
    int rx = x / 3 * 3;

    for (int j = 0; j < 9; j++) {
        if (sudoku[j][x] == number) {
            possible = false;
            break;
        }

        if (sudoku[y][j] == number) {
            possible = false;
            break;
        }

        if (sudoku[ry + (j/3)][rx + (j%3)] == number) {
            possible = false;
            break;
        }
    }

    return possible;
}

void backtracking(int pos) {
    if (finish) return;
    if (pos == 81) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        finish = true;
    }
    
    int y = pos / 9;
    int x = pos % 9;
    
    if (sudoku[y][x] != 0) {
        backtracking(pos + 1);
        return;
    }

    for (int number = 1; number <= 9; number++) {
        if (isPossible(y, x, number)) {
            sudoku[y][x] = number;
            backtracking(pos + 1);
            sudoku[y][x] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> sudoku[i][j];
        }
    }

    backtracking(0);

    return 0;
}
