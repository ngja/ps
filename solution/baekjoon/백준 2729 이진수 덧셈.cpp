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
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        bitset<82> bit1, bit2;
        cin >> bit1 >> bit2;

        bitset<82> result;
        int next = 0;
        for (int j = 0; j < 81; ++j) {

            int sum = bit1[j] + bit2[j];

            if (sum == 0) {
                sum = next;
                next = 0;
            } else if (sum == 1) {
                if (next == 1) {
                    sum = 0;
                }
            } else if (sum == 2) {
                if (next == 1) {
                    next = 1;
                    sum = 1;
                } else {
                    next = 1;
                    sum = 0;
                }
            }

            result[j] = sum;
        }

        vector<int> ans;
        bool pushStart = false;
        for (int j = 80; j >= 0; --j) {
            if (pushStart) {
                ans.push_back(result[j]);
            } else {
                if (result[j] == 1) {
                    pushStart = true;
                    ans.push_back(result[j]);
                }
            }
        }

        if (!pushStart) {
            cout << 0;
        } else {
            for (auto k : ans) {
                cout << k;
            }
        }
        cout << "\n";
    }

    return 0;
}