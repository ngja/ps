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
const int INF = 2'000'000'000;
const ll LL_INF = 10'000'000'000LL;

int n;
int price[1001];
int dp[1001];

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    // dp[n] = min(dp[n], dp[n-i] + price[i]);

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> price[i];
        dp[i] = price[i];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            dp[i] = min(dp[i], dp[i-j] + price[j]);
        }
    }

    cout << dp[n] << "\n";

    return 0;
}