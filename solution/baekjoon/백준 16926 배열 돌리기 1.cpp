#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int originalArr[350][350];
int resultArr[350][350];
int moveArr[350][350];
pair<int, int> moveDir[4] = { {1, 0}, {0, 1} , {-1, 0}, {0, -1}};
int n, m, rotateCount;
int minHalf; // min(n, m) / 2;

void getMove() {
    for (int i = 0; i < minHalf; i++) {
        int y = i;
        int x = i;

        int yRepeat = n - 1 - (2 * i);
        int xRepeat = m - 1 - (2 * i);
        for (int j = 0; j < yRepeat; j++) {
            moveArr[y + j][x] = 0;
        }

        for (int j = 0; j < xRepeat; j++) {
            moveArr[y + yRepeat][x + j] = 1;
        }

        for (int j = 0; j < yRepeat; j++) {
            moveArr[y + yRepeat - j][x + xRepeat] = 2;
        }

        for (int j = 0; j < xRepeat; j++) {
            moveArr[y][x + xRepeat - j] = 3;
        }
    }
}

int main() {

    cin >> n >> m >> rotateCount;
    minHalf = min(n, m) / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> originalArr[i][j];
        }
    }

    getMove();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int currentI = i;
            int currentJ = j;
            for (int k = 0; k < rotateCount; ++k) {
                int nextI = currentI + moveDir[moveArr[currentI][currentJ]].first;
                int nextJ = currentJ + moveDir[moveArr[currentI][currentJ]].second;
                currentI = nextI;
                currentJ = nextJ;
            }
            resultArr[currentI][currentJ] = originalArr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << resultArr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
