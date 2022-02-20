#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <cstring>
using namespace  std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

const int INF = 987654321;
const int MAX_SIZE = 20;

int castle[MAX_SIZE][MAX_SIZE];
int row, column;
int range;
int ans = 0;

vector<int> getPosition(int a) {
    vector<int> position;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (a & 1)
            position.push_back(i);

        a = a >> 1;


        if (position.size() == 3)
            break;
    }
    return position;
}

int getLength(int r1, int c1, int r2, int c2) {
    return abs(r1-r2) + abs(c1 - c2);
}

int getKill(vector<int> p) {
    int kill = 0;
    int c[MAX_SIZE][MAX_SIZE];
    memcpy(c, castle, sizeof(castle));
    for (int time = row; time > 0; time--) {
        vector<pair<int, int>> deadEnemy;
        for (int archer : p) {
            // 각 궁수가 어느 적을 쏠지 계산
            int targetLength = INF; 
            pair<int, int> enemyPosition = {INF, INF};
            for (int i = time-1; i >= 0; i--) {
                for (int j = 0; j < column; j++) {
                    if (c[i][j] == 1 || c[i][j] == 2) {
                        int tempLength = getLength(time, archer, i, j);
                        if (tempLength <= range && tempLength <= targetLength) {
                            if (tempLength < targetLength) {
                                targetLength = tempLength;
                                enemyPosition = {i, j};
                            } else if (enemyPosition.second > j) {
                                targetLength = tempLength;
                                enemyPosition = {i, j};
                            }
                        }
                    }
                }
            }

            if (targetLength != INF && enemyPosition.first != INF) {
                if (c[enemyPosition.first][enemyPosition.second] == 1) kill++;
                c[enemyPosition.first][enemyPosition.second] = 2;
                deadEnemy.push_back(enemyPosition);
            }

        }

        for (pair<int, int> enemy : deadEnemy) {
            c[enemy.first][enemy.second] = 0;
        }
    }
    return kill;
}

int main() {
    cin >> row >> column >> range;
    for (int y = 0; y < row; ++y) {
        for (int x = 0; x < column; ++x) {
            cin >> castle[y][x];
        }
    }


    for (int i = 0; i < (1<<column); i++) {
        if (__builtin_popcount(i) == 3) {
            vector<int> p = getPosition(i);
            int tempAns = getKill(p);
            if (ans < tempAns)
                ans = tempAns;
        }
    }

    cout << ans << "\n";

    return 0;
}
