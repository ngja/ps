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

int len[405][405];
int v, e;

int main() {

    cin >> v >> e;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; ++j) {
            if (i == j)
                len[i][j] = 0;
            else
                len[i][j] = INF;
        }
    }

    for (int i = 0; i < e; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        len[a][b] = c;
    }

    for (int k = 1; k <= v; ++k) {
        for (int i = 1; i <= v; ++i) {
            for (int j = 1; j <= v; ++j) {
                if (len[i][k] != INF && len[k][j] != INF)
                    len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
            }
        }
    }
    int ans = INF;

    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            if (i == j)
                continue;

            if (len[i][j] != INF && len[j][i] != INF) {
                ans = min(ans, len[i][j] + len[j][i]);
            }
        }
    }

    if (ans == INF)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}
