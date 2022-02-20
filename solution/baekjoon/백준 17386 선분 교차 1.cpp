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

using namespace std;


int ccw(pll a, pll b, pll c) {
    ll temp = a.first*b.second + b.first*c.second + c.first*a.second;
    temp = temp - (a.second*b.first + b.second*c.first + c.second*a.first);
    if (temp > 0) {
        return 1; // Counterclockwise
    } else if (temp < 0) {
        return -1; // Clockwise
    } else {
        return 0; // Linear
    }
}

int intersect(pll a, pll b, pll c, pll d) {
    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }

    return ab <= 0 && cd <= 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    ll x1, x2, x3, x4;
    ll y1, y2, y3, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    pll a = {x1, y1};
    pll b = {x2, y2};
    pll c = {x3, y3};
    pll d = {x4, y4};

    cout << intersect(a, b, c, d) << "\n";

    return 0;
}
