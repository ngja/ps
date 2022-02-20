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

const int MAX = 100000;
vector<vector<int>> vt;
vector<vector<int>> rvt;
vector<int> sccGroup;
vector<int> sccIndegree;
bool visited[MAX + 1];

void dfs(int v, stack<int>& st) {
    visited[v] = true;
    for (int next : vt[v]) {
        if (visited[next])
            continue;
        dfs(next, st);
    }
    st.push(v);
}

void kosaraju(int v, int c) {
    visited[v] = true;
    sccGroup[v] = c;
    for (int next : rvt[v]) {
        if (visited[next]) {
            if (sccGroup[next] != sccGroup[v]) { // 다른 그룹으로 가는 경우, 현재 sccGroup Indegree 증가
                sccIndegree[c]++;
            }
            continue;
        }
        kosaraju(next, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vt.assign(n, vector<int> ());
        rvt.assign(n, vector<int> ());
        sccGroup.resize(n, -1);
        sccIndegree.clear();
        fill(visited, visited + n, false);
        stack<int> st;

        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            a -= 1;
            b -= 1;
            vt[a].push_back(b);
            rvt[b].push_back(a);
        }

        for (int i = 0; i < n; ++i) {
            if (visited[i])
                continue;
            dfs(i, st);
        }

        fill(visited, visited + n, false);

        int group = 0;
        while (!st.empty()) {
            int cur = st.top();
            st.pop();
            if (visited[cur])
                continue;
            sccIndegree.push_back(0);
            kosaraju(cur, group);
            group++;
        }

        int ans = 0;
        for (int indegree : sccIndegree) {
            if (indegree == 0)
                ans++;
        }

        cout << ans << "\n";
    }

    return 0;
}