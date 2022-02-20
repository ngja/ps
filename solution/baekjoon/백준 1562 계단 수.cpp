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
typedef pair<int, int> pi;

using namespace std;

// dp[자리수][마지막수][0~1 사용여부]
ll dp[101][10][1<<10];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    dp[1][0][1<<0] = 0;
    for (int i = 1; i <= 9; i++) {
        dp[1][i][1<<i] = 1;
    }

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j-1 >= 0) {
                for (int k = 0; k < (1<<10); k++) {
                    if (dp[i-1][j-1][k] > 0) {
                        dp[i][j][(1<<j) | (k)] += dp[i-1][j-1][k];
                        dp[i][j][(1<<j) | (k)] %= 1000000000;
                    }
                }
            }

            if (j+1 <= 9) {
                for (int k = 0; k < (1<<10); k++) {
                    if (dp[i-1][j+1][k] > 0) {
                        dp[i][j][(1<<j) | (k)] += dp[i-1][j+1][k];
                        dp[i][j][(1<<j) | (k)] %= 1000000000;
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 9; i++) {
        ans += dp[n][i][(1<<10)-1];
        ans %= 1000000000;
    }

    cout << ans << "\n";

    return 0;
}
