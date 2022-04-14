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

bool visit[1001][1001];

int main() {
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    queue<vector<int>> q;

    int a, b, c;
    cin >> a >> b >> c;
    vector<int> init = {a, b, c};

    if ((a+b+c) % 3 == 0) {
        std::sort(init.begin(), init.end());
        q.push(init);
    }

    bool possible = false;
    while(!q.empty()) {
        vector<int> now = q.front();
        q.pop();
        visit[now[0]][now[1]] = true;

        if (now[0] == now[1] && now[1] == now[2]) {
            possible = true;
            break;
        }

        for (int i = 0; i < 3; i++) {
            int left = i;
            int right = (i+1) % 3;
            int mid = (i+2) % 3;

            int lo = min(left, right);
            int hi = max(left, right);

            int nextA = now[lo] + now[lo];
            int nextB = now[hi] - now[lo];
            int nextC = now[mid];

            vector<int> next = {nextA, nextB, nextC};
            std::sort(next.begin(), next.end());

            if (visit[next[0]][next[1]]) {
                continue;
            }

            q.push(next);
        }
    }

    cout << possible << "\n";

    return 0;
}