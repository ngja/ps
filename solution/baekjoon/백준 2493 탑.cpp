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
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    int n;
    cin >> n;

    vector<int> tower(n+1);
    vector<int> ans(n+1);

    for (int i = 1; i <= n; ++i) {
        cin >> tower[i];
    }

    stack<pair<int, int>> monotone; // {높이, index}

    for (int i = 1; i <= n; ++i) {
        while (true) {
            if (monotone.empty()) {
                ans[i] = 0;
                monotone.push({tower[i], i});
                break;
            }

            pair<int, int> top = monotone.top();

            if (top.first < tower[i]) {
                monotone.pop();
                continue;
            } else {
                ans[i] = top.second;
                if (top.first == tower[i])
                    monotone.pop();
                monotone.push({tower[i], i});
                break;
            }
        }
    }

    for (int i = 1; i <= n; ++i)
        cout << ans[i] << " ";
    cout << "\n";


    return 0;
}