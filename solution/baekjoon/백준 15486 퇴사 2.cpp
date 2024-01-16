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



int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> t(n+1); // 기간
    vector<int> p(n+1); // 금액
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    vector<int> dp(n+2, 0);
    // dp[n] = n 일에 가장 많은 금액
    // 우리가 구할 것 = dp[n+1]
    // i = 1일 부터 n 일 까지 가면서
    // dp[i] = max(dp[i], dp[i-1]) 전날 최댓값이랑 현재 최댓값이랑 비교해서 초기화
    // dp[i-1+t[i]] = max(dp[i-1+t[i]], dp[i-1] + p[i]) 오늘의 작업을 했을 경우 미래의 최댓값 업데이트

    for (int i = 1; i <= n; i++) {
        dp[i] = max(dp[i-1], dp[i]);
        int nextPos = i - 1 + t[i];
        if (nextPos > n) {
            continue;
        }
        dp[nextPos] = max(dp[nextPos], dp[i-1] + p[i]);
    }
    cout << dp[n] << "\n";
}