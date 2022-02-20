#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n;
int dp[50005];

int main() {

    cin >> n;

    for (int i = 1; i * i <= n; ++i) {
        dp[i * i] = 1;
    }

    for (int i = 2; i <= n; ++i) {

        int minSol = INF;
        if (dp[i] == 1)
            continue;
        for (int j = 1; j <= i/2; ++j) {
            int curSol = dp[j] + dp[i-j];
            if (minSol > curSol) {
                minSol = curSol;
                if (minSol == 2)
                    break;
            }
        }

        dp[i] = minSol;
    }

    cout << dp[n] << "\n";

    return 0;
}
