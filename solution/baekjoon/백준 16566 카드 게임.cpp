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

int n, m, k;
vector<int> cards;
vector<int> expects;

int parent[4000001];

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
    if (a != b) {
        parent[b] = a;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m >> k;
    cards.resize(m);
    expects.resize(k);
    for (int i = 0; i < m; ++i) {
        cin >> cards[i];
    }

    for (int i = 0; i < k; ++i) {
        cin >> expects[i];
    }
    
    sort(cards.begin(), cards.end());

    for (int i = 0; i < m; ++i) {
        makeSet(i);
    }

    for (int i = 0; i < k; ++i) {
        int currentIndex = upper_bound(cards.begin(), cards.end(), expects[i]) - cards.begin();

        int groupNo = findSet(currentIndex);
        cout << cards[groupNo] << "\n";

        int nextIndex = upper_bound(cards.begin(), cards.end(), cards[groupNo]) - cards.begin();
        unionSet(nextIndex, currentIndex);
    }

    return 0;
}