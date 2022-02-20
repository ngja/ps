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


int info[55][55];
int inning;
int ans = 0;

int getScore(vector<int> player) {
    int score = 0;
    int pos = 1;
    int outCount = 0;
    int end = 1;
    deque<int> ground;

    while(true) {
        if (end > inning) {
            break;
        }
        if (pos == 10)
            pos = 1;

        if (pos == 4) {
            if (info[end][1] == 0) {
                outCount++;
                pos++;
                if (outCount == 3) {
                    outCount = 0;
                    ground.clear();
                    end++;
                    continue;
                }
            } else if (info[end][1] == 4) {
                score += (ground.size() + 1);
                ground.clear();
                pos++;
            } else {
                int size = ground.size();
                while(size--) {
                    int t = ground.front();
                    ground.pop_front();
                    int nextT = t + info[end][1];
                    if (nextT >= 4) {
                        score++;
                    } else {
                        ground.push_back(nextT);
                    }
                }
                ground.push_back(info[end][1]);
                pos++;
            }
        } else {
            int z = 0;
            if (pos < 4)
                z = pos-1;
            else if (pos > 4)
                z = pos-2;
            if (info[end][player[z]] == 0) {
                outCount++;
                pos++;
                if (outCount == 3) {
                    outCount = 0;
                    ground.clear();
                    end++;
                    continue;
                }
            } else if (info[end][player[z]] == 4) {
                score += (ground.size() + 1);
                ground.clear();
                pos++;
            } else {
                int size = ground.size();
                while(size--) {
                    int t = ground.front();
                    ground.pop_front();
                    int nextT = t + info[end][player[z]];
                    if (nextT >= 4) {
                        score++;
                    } else {
                        ground.push_back(nextT);
                    }
                }
                ground.push_back(info[end][player[z]]);
                pos++;
            }
        }
    }
    return score;
}

void solution() {
    vector<int> player = { 2, 3, 4, 5, 6, 7, 8, 9 };

    do {
        int tempScore = getScore(player);
        ans = max(ans, tempScore);
    } while(next_permutation(player.begin(), player.end()));


}

int main() {

    cin >> inning;

    for (int i = 1; i <= inning; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> info[i][j];
        }
    }

    solution();

    cout << ans << '\n';
    return 0;
}
