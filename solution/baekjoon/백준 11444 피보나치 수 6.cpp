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

int main() {

    ll m = 1000000007;
    ll n;
    cin >> n;

    ll ans[2][2] = {{1, 0}, {0, 1}};
    ll arr[2][2] = {{1, 1}, {1, 0}};

    while (n > 0) {
        if (n % 2 == 1) {
            ll temp[2][2];

            temp[0][0] = ((ans[0][0] * arr[0][0]) % m + (ans[0][1] * arr[1][0]) % m) % m;
            temp[0][1] = ((ans[0][0] * arr[0][1]) % m + (ans[0][1] * arr[1][1]) % m) % m;
            temp[1][0] = ((ans[1][0] * arr[0][0]) % m + (ans[1][1] * arr[1][0]) % m) % m;
            temp[1][1] = ((ans[1][0] * arr[0][1]) % m + (ans[1][1] * arr[1][1]) % m) % m;

            ans[0][0] = temp[0][0];
            ans[0][1] = temp[0][1];
            ans[1][0] = temp[1][0];
            ans[1][1] = temp[1][1];
        }

        ll t[2][2];

        t[0][0] = ((arr[0][0] * arr[0][0]) % m + (arr[0][1] * arr[1][0]) % m) % m;
        t[0][1] = ((arr[0][0] * arr[0][1]) % m + (arr[0][1] * arr[1][1]) % m) % m;
        t[1][0] = ((arr[1][0] * arr[0][0]) % m + (arr[1][1] * arr[1][0]) % m) % m;
        t[1][1] = ((arr[1][0] * arr[0][1]) % m + (arr[1][1] * arr[1][1]) % m) % m;

        arr[0][0] = t[0][0];
        arr[0][1] = t[0][1];
        arr[1][0] = t[1][0];
        arr[1][1] = t[1][1];

        n /= 2;
    }

    cout << ans[0][1] << "\n";



    return 0;
}
