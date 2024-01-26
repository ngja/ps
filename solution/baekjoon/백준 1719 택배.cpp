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
using ll = long long;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const ll MOD = 1'000'000'007LL;
const int INF = 1'000'000'10;
const ll LL_INF = 10'000'000'000LL;

int n, m;
int adj[202][202];
int dist[202][202];
int ans[202][202];

int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c; // a - b 거리 c
        cin >> a >> b >> c;
        adj[a][b] = c;
        adj[b][a] = c;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else if (adj[i][j]) dist[i][j] = adj[i][j];
            else dist[i][j] = INF;

            if (i != j) {
                if (adj[i][j]) {
                    ans[i][j] = j;
                }
            }
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i][j] == 0) {
                cout << "- ";
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }
}