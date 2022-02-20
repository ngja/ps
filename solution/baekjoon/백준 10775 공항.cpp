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
const ll LL_INF = 10000000000LL;
const int INF = 2000000000;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pll, pll> ppll;

int g, p;
set<int> gates;
int airplanes[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> g >> p;
    for (int i = 1; i <= g; ++i) {
        gates.insert(i);
    }
    for (int i = 0; i < p; ++i) {
        cin >> airplanes[i];
    }

    int ans = 0;
    for (int i = 0; i < p; ++i) {
        set<int>::iterator iter = gates.upper_bound(airplanes[i]);

        if (iter == gates.begin()) {
            break;
        } else {
            iter--;
            gates.erase(iter);
            ans++;
        }

        if (gates.empty()) {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}