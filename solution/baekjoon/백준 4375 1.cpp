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
    int n;
    while (cin >> n) {
        int ans = 1;
        int m = 1;

        while (true) {
            if (m % n == 0) {
                cout << ans << "\n";
                break;
            }

            ans++;
            m = 10 * m + 1;
            m = m % n;
        }
    }
    return 0;
}