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

const int SIZE = 10;
int paper[SIZE][SIZE];
int extra[6] = {0, 5, 5, 5, 5, 5};
int ans = INF;
int cnt;

void check(int y, int x) {
    if (x == SIZE)
        check(y+1, 0);

    if (y == SIZE) {
        ans = min(ans, cnt);
        return;
    }

    if (paper[y][x] == 0) {
        check(y, x + 1);
        return;
    }

    for (int s = 5; s >= 1; s--) {
        if (extra[s] <= 0 || y + s > SIZE || x + s > SIZE)
            continue;

        bool impossible = false;
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < s; j++) {
                if (paper[y+i][x+j] == 0) {
                    impossible = true;
                    break;
                }
            }
            if (impossible)
                break;
        }
        if (impossible)
            continue;

        for (int i = 0; i < s; i++)
            for (int j = 0; j < s; j++)
                paper[y + i][x + j] = 0;
        extra[s]--;
        cnt++;

        check(y, x + s);

        for (int i = 0; i < s; i++)
            for (int j = 0; j < s; j++)
                paper[y + i][x + j] = 1;
        extra[s]++;
        cnt--;
    }
}

int main() {

    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> paper[i][j];

    check(0, 0);

    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
