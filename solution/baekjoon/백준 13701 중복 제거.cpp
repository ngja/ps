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

const int INF = 2000000000;
const ll LL_INF = 10000000000LL;

int store[1 << 20]; // 2^20 개 + 각 칸이 0~31까지 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a;
    while (cin >> a) {
        int inside = a % 32;
        int outside = a / 32;

        if (store[outside] & (1 << inside)) {
            continue;
        }

        store[outside] |= (1 << inside);
        cout << a << " ";
    }

    return 0;
}