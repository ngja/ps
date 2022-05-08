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

int n, m;
int card[500001];
int target[500001];

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> card[i];
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> target[i];
    }

    sort(card, card + n);

    for (int i = 0; i < m; ++i) {

        int hi = upper_bound(card, card + n, target[i]) - card;
        int lo = lower_bound(card, card + n, target[i]) - card;

        cout << hi - lo << " ";
    }

    return 0;
}