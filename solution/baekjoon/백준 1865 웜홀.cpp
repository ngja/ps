#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

const int INF = 1000000000;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int t;
int n, m, w;
vector<tuple<int, int, int>> edges;

bool minusCycle() {
    vector<int> dist(n+1, INF);
    dist[1] = 0;
    vector<int> p(n-1);
    bool x;
    for (int i = 0; i < n; ++i) {
        x = false;
        for (auto e : edges) {
            int a, b, d;
            tie(a, b, d) = e;
            if (dist[b] > dist[a] + d) {
                dist[b] = dist[a] + d;
                x = true;
            }
        }
    }
    return x;
}

int main() {

    cin >> t;

    while (t--) {
        cin >> n >> m >> w;
        edges.clear();

        for (int i = 0; i < m; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            edges.emplace_back(a, b, d);
            edges.emplace_back(b, a, d);
        }

        for (int i = 0; i < w; ++i) {
            int a, b, d;
            cin >> a >> b >> d;
            edges.emplace_back(a, b, -d);
        }

        if (minusCycle()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
