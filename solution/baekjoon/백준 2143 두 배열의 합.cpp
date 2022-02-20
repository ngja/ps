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

using namespace std;

ll t, n, m;
ll a[1010];
ll aSum[1010];
ll b[1010];
ll bSum[1010];

int main() {
//    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> t;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        aSum[i] = aSum[i-1] + a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> b[i];
        bSum[i] = bSum[i-1] + b[i];
    }


    vector<ll> aSubset;
    vector<ll> bSubset;

    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            aSubset.push_back(aSum[j] - aSum[i]);
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = i+1; j <= m; j++) {
            bSubset.push_back(bSum[j] - bSum[i]);
        }
    }

    sort(aSubset.begin(), aSubset.end());
    sort(bSubset.begin(), bSubset.end());

    ll ans = 0;
    for (ll one : aSubset) {
        ll another = t - one;
        long long int possibleCount = upper_bound(bSubset.begin(), bSubset.end(), another) -
                                      lower_bound(bSubset.begin(), bSubset.end(), another);
        ans += possibleCount;
    }

    cout << ans << "\n";

    return 0;
}
