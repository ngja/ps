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

const int INF = ~(1 << 31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int v;
vector<vector<pair<int, int>>> tree; // <정점, 거리>
bool visited[100005];
int ans = 0;
int candidate;

void dfs(int s, int length) {
    if (visited[s]) return;
    visited[s] = true;
    if (ans < length) {
        ans = length;
        candidate = s;
    }
    for (pair<int, int> d : tree[s]) {
        dfs(d.first, length + d.second);
    }
}

int main() {

    cin >> v;
    tree.resize(v+1);

    for (int i = 0; i < v; ++i) {
        int departure;
        cin >> departure;
        while(true) {
            int dest;
            cin >> dest;
            if (dest == -1)
                break;
            int len;
            cin >> len;

            tree[departure].push_back({dest, len});
        }
    }

    dfs(1, 0);
    ans = 0;
    for (int i = 0; i <= v; ++i) {
        visited[i] = false;
    }
    dfs(candidate, 0);

    cout << ans << "\n";
    return 0;
}
