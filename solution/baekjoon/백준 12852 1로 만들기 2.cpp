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

int dp[1000005];
int parent[1000005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n;
    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    parent[1] = 0;
    parent[2] = 1;
    parent[3] = 1;

    for (int i = 4; i <= n; i++) {
        int one = -1;
        int two = -1;
        int three = dp[i-1] + 1;

        if (i % 3 == 0) {
            one = dp[i/3] + 1;
        }
        if (i % 2 == 0) {
            two = dp[i/2] + 1;
        }

        if (one == -1 && two == -1) {
            dp[i] = three;
            parent[i] = i - 1;
        } else if (one == -1) {
            if (two <= three) {
                dp[i] = two;
                parent[i] = i / 2;
            } else {
                dp[i] = three;
                parent[i] = i - 1;
            }
        } else if (two == -1) {
            if (one <= three) {
                dp[i] = one;
                parent[i] = i / 3;
            } else {
                dp[i] = three;
                parent[i] = i - 1;
            }
        } else {
            int four = min(one, min(two, three));

            if (four == one) {
                dp[i] = one;
                parent[i] = i / 3;
            } else if (four == two) {
                dp[i] = two;
                parent[i] = i / 2;
            } else if (four == three) {
                dp[i] = three;
                parent[i] = i - 1;
            }
        }
    }

    cout << dp[n] << "\n";
    int idx = n;
    while (idx != 0) {
        cout << idx << " ";
        idx = parent[idx];
    }


    return 0;
}
