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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

using namespace std;

int cost[5][5] = {{0, 2, 2, 2, 2},
                  {2, 1, 3, 4, 3},
                  {2, 3, 1, 3, 4},
                  {2, 4, 3, 1, 3},
                  {2, 3, 4, 3, 1}};

int dp[1<<5][100001];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> commands;
    for (int i = 0; i <= 100000; i++) {
        int input;
        cin >> input;
        if (input == 0)
            break;
        commands.push_back(input);
        for (int j = 0; j < 1 << 5; j++) {
            dp[j][i] = INF;
        }
    }

    if (commands.empty()) {
        cout << "0\n";
        return 0;
    }

    int firstPos = 1;
    firstPos |= (1 << commands[0]);
    dp[firstPos][0] = 2;

    for (int i = 1; i < commands.size(); i++) {
        for (int j = 0; j < 1 << 5; j++) { // j 현재 발 위치
            if (dp[j][i-1] == INF) {
                continue;
            }

            // 커맨드 위치에 발이 있는 경우
            if (j & (1 << commands[i])) {
                dp[j][i] = min(dp[j][i-1] + 1, dp[j][i]);
                continue;
            }

            // 커맨드 위치에 발이 없는 경우
            for (int k = 0; k < 5; k++) {
                if (j & (1 << k)) { // k 번째에 발이 있는 경우 k번째 발을 command 위치로 옮긴다.
                    int nextPos = j;
                    nextPos &= ~(1 << k);
                    nextPos |= (1 << commands[i]);
                    dp[nextPos][i] = min(dp[j][i-1] + cost[k][commands[i]], dp[nextPos][i]);
                }
            }
        }
    }


    int ans = INF;
    for (int i = 0; i < (1 << 5); i++) {
        if (ans > dp[i][commands.size()-1])
            ans = dp[i][commands.size()-1];
    }

    cout << ans << "\n";

    return 0;
}
