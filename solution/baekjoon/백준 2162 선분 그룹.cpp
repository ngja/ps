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
typedef pair<pll, pll> ppll;

using namespace std;

int parent[3005];
int groupCount[3005];
set<int> parentGroup;

void makeSet(int v) {
    parent[v] = v;
}

int findSet(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = findSet(parent[v]);
}

void unionSet(int a, int b) {
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[b] = a;
}

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

    int n;
    cin >> n;

    vector<ppll> points;
    points.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }


    for (int i = 0; i < n; i++) {
        cin 
        >> points[i].first.first 
        >> points[i].first.second
        >> points[i].second.first
        >> points[i].second.second;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int isIntersect = intersect(points[i].first, points[i].second, points[j].first, points[j].second);
            if (isIntersect) {
                unionSet(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        groupCount[findSet(i)]++;
        parentGroup.insert(findSet(i));
    }

    int maxGroupCount = 0;
    for (int i = 0; i < n; i++) {
        if (maxGroupCount < groupCount[i])
            maxGroupCount = groupCount[i];
    }

    cout << parentGroup.size() << "\n";
    cout << maxGroupCount << "\n";
    return 0;
}
