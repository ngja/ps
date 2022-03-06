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
/*
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
*/

    stack<char> st;
    queue<char> tagQueue;
    queue<char> ans;
    string s;

    getline(cin, s);

    bool tag = false;
    for (char c : s) {

        if (c == '<') {
            tag = true;
            tagQueue.push(c);

            while (!st.empty()) {
                char top = st.top();
                ans.push(top);
                st.pop();
            }
        } else if (c == '>') {
            tag = false;
            while (!tagQueue.empty()) {
                char first = tagQueue.front();
                ans.push(first);
                tagQueue.pop();
            }
            ans.push(c);
        } else {
            if (tag) {
                tagQueue.push(c);
            } else {
                if (c == ' ') {
                    while (!st.empty()) {
                        char top = st.top();
                        ans.push(top);
                        st.pop();
                    }
                    ans.push(c);
                } else {
                    st.push(c);
                }
            }
        }
    }

    while (!st.empty()) {
        char top = st.top();
        ans.push(top);
        st.pop();
    }

    while (!ans.empty()) {
        cout << ans.front();
        ans.pop();
    }

    return 0;
}