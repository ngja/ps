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

const int MAX_SIZE = 100001;
int n, m;
int numbers[MAX_SIZE];
int segmentTree[4 * MAX_SIZE];

int getMinIndex(int y, int x) {
    if (numbers[y] == numbers[x]) {
        return min(y, x);
    } else if (numbers[y] < numbers[x]) {
        return y;
    } else {
        return x;
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        segmentTree[v] = tl;
    } else {
        int tm = (tl + tr) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        int temp = getMinIndex(segmentTree[2 * v], segmentTree[2 * v + 1]);
        segmentTree[v] = temp;
    }
}

int segmentMin(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
   if (l == tl && r == tr)
       return segmentTree[v];
   int tm = (tl + tr) / 2;
   return getMinIndex(
           segmentMin(2 * v, tl, tm, l, min(r, tm)),
           segmentMin(2 * v + 1, tm + 1, tr, max(l, tm + 1), r)
           );
}

void updateSegment(int v, int tl, int tr, int pos, int newVal) {
    if (tl == tr) {
        segmentTree[v] = newVal;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            updateSegment(2 * v, tl, tm, pos, newVal);
        else
            updateSegment(2 * v + 1, tm + 1, tr, pos, newVal);
        segmentTree[v] = getMinIndex(segmentTree[2 * v], segmentTree[2 * v + 1]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    numbers[0] = INF;
    for (int i = 1; i <= n; ++i) {
        cin >> numbers[i];
    }
    
    build(1, 1, n);


    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1) {
            numbers[b] = c;
            updateSegment(1, 1, n, b, b);
        } else {
            int minValueIndex = segmentMin(1, 1, n, b, c);
            cout << minValueIndex << "\n";
        }
    }
    
    return 0;
}