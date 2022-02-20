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
typedef pair<int, int> pi;

int main() {

    ll a, b;
    cin >> a >> b;

    queue<ll> q;

    q.push(a);

    int count = 1;
    while(!q.empty()) {
        unsigned int size = q.size();
        for (int i = 0; i < size; ++i) {
            ll cur = q.front(); q.pop();
            if (cur == b) {
                cout << count << "\n";
                return 0;
            }
            ll next1 = cur * 2;
            ll next2 = cur * 10 + 1;
            if (next1 <= b)
                q.push(next1);
            if (next2 <= b)
                q.push(next2);
        }

        count++;
    }

    cout << "-1\n";

    return 0;
}
