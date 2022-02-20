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
const ll LL_INF = 10000000000LL;
const int INF = 2000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

int n, m;
int memory[101];
int cost[101];
int dp[101][100010] = { 0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int totalCost = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> memory[i];
    }
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
        totalCost += cost[i];
    }

    for (int i = 1; i <= n; ++i) { // 1번 앱부터 n번 앱까지
        for (int j = 0; j <= totalCost; ++j) { // cost 0 부터 cost totalCost 까지
            if (j >= cost[i]) {
                dp[i][j] = max(dp[i-1][j-cost[i]] + memory[i], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for (int j = 0; j <= totalCost; ++j) {
        if (dp[n][j] >= m) {
            cout << j << "\n";
            break;
        }
    }

    return 0;
}