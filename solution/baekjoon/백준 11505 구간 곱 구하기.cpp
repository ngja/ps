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

const int INF = 2000000000;
const ll LL_INF = 10000000000LL;

const int MAX_SIZE = 1000001;
int n, m, k;
ll numbers[MAX_SIZE];
ll segmentTree[4 * MAX_SIZE];

ll multiply(ll y, ll x) {
    return (y * x) % 1000000007;
}

void build(ll a[], int v, int tl, int tr) {
    if (tl == tr) {
        segmentTree[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, 2 * v, tl, tm);
        build(a, 2 * v + 1, tm + 1, tr);
        segmentTree[v] = multiply(segmentTree[2 * v], segmentTree[2 * v + 1]);
    }
}

ll getSegmentMultiply(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 1;
    if (l == tl && r == tr)
        return segmentTree[v];
    int tm = (tl + tr) / 2;
    return multiply(getSegmentMultiply(2 * v, tl, tm, l, min(r, tm)),
                    getSegmentMultiply(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

void updateSegment(int v, int tl, int tr, int pos, int newValue) {
    if (tl == tr) {
        segmentTree[v] = newValue;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateSegment(2 * v, tl, tm, pos, newValue);
        else
            updateSegment(2 * v + 1, tm + 1, tr, pos, newValue);
        segmentTree[v] = multiply(segmentTree[2 * v], segmentTree[2 * v + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }

    build(numbers, 1, 1, n);

    for (int i = 0; i < m + k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) { // 변경
            updateSegment(1, 1, n, b, c);
        } else if (a == 2) { // 곱 출력
            cout << getSegmentMultiply(1, 1, n, b, c) << "\n";
        }
    }

    return 0;
}