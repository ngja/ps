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

ll X = 1000000007;

// return a^n
ll superPow(ll a, ll n) {
    ll result = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            result = (result * a) % X;
        }
        a = (a * a) % X;
        n /= 2;
    }
    return result;
}

int main() {

    int m; // 주사위 수
    cin >> m;
    ll ans = 0;
    for (int i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;

        ans += ((b % X) * (superPow(a, X-2))) % X;
    }
    ans %= X;

    cout << ans << "\n";

    return 0;
}
