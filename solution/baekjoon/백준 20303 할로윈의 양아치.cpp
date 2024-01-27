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

// disjoint set
vector<int> parent, depth;

void make_set(int v) {
    parent[v] = v;
    depth[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (depth[a] < depth[b])
            swap(a, b);
        parent[b] = a;
        if (depth[a] == depth[b])
            depth[a]++;
    }
}

int main() {
//    ios_base :: sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);

    int n, m, k; // 아이 수, 친구 관계 수, 울리면 안되는 최소 수
    cin >> n >> m >> k;

    vector<int> candy;
    candy.resize(n + 1);
    parent.resize(n + 1);
    depth.resize(n + 1);

    // 캔디수 입력과 disjoint set 초기화
    for (int i = 1; i <= n; i++) {
        cin >> candy[i];
        make_set(i);
    }

    // 친구 관계 입력과 관계 합치기
    for (int i = 1; i <= m; i++) {
        int a, b; // a-b 친구 관계
        cin >> a >> b;
        union_sets(a, b);
    }

    // disjoint set으로 그룹화 하기
    vector<pair<int, int>> bundle; // pair<인원수, 캔디수>
    bundle.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int p = find_set(i);
        bundle[p].first += 1;
        bundle[p].second += candy[i];
    }

    vector<pair<int, int>> finalBundle; // pair<인원수, 캔디수>
    for (int i = 1; i <= n; i++) {
        if (bundle[i].first != 0) {
            finalBundle.emplace_back(bundle[i].first, bundle[i].second);
        }
    }

    // dp
    vector<int> dp;
    dp.resize(k+1);
    dp[0] = 0;
    for (pair<int, int>& i : finalBundle) {
        for (int j = k - 1 - i.first; j >= 0; j--) {
            dp[j + i.first] = max(dp[j + i.first], dp[j] + i.second);
        }
    }
    cout << dp[k - 1];
}