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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int D(int x) {
    return (2*x)%10000;
}

int S(int x) {
    if (x==0)
        return 9999;
    else
        return x-1;
}

int L(int x) {
    int l = 10 * x;
    return (l%10000) + (l/10000);
}

int R(int x) {
    int r = x%10;
    return (x/10)+(r*1000);
}

int main() {

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int a, b;
        cin >> a >> b;

        queue<pair<string, int>> q;
        bool visit[10000] = {false, };
        q.push({"", a});
        visit[a] = true;

        while(true) {
            pair<string, int> cur = q.front(); q.pop();

            if (cur.second == b) {
                cout << cur.first << "\n";
                break;
            }

            int d = D(cur.second);
            if (!visit[d]) {
                visit[d] = true;
                q.push({cur.first+"D", d});
            }

            int s = S(cur.second);
            if (!visit[s]) {
                visit[s] = true;
                q.push({cur.first+"S", s});
            }

            int l = L(cur.second);
            if (!visit[l]) {
                visit[l] = true;
                q.push({cur.first+"L", L(cur.second)});
            }

            int r = R(cur.second);
            if (!visit[r]) {
                visit[r] = true;
                q.push({cur.first+"R", R(cur.second)});
            }
        }
    }

    return 0;
}
