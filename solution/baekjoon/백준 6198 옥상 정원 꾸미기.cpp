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


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> input;
    input.assign(n, 0);
    stack<ll> st;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        cin >> input[i];
    }

    st.push(input[0]);

    for (int i = 1; i < n; ++i) {

        ll top = st.top();
        if (top > input[i]) {
            ans += st.size();
            st.push(input[i]);
        } else {

            while (!st.empty()) {
                ll cur = st.top();

                if (cur > input[i]) {
                    break;
                }

                st.pop();
            }
            ans += st.size();
            st.push(input[i]);
        }
    }

    cout << ans << "\n";

    return 0;
}