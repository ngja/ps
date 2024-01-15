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
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n--) {
        string first, second;
        cin >> first >> second;

        int alphabet[26];
        fill_n(alphabet, 26, 0);

        for (char c : first) {
            alphabet[c - 'a']++;
        }
        for (char c : second) {
            alphabet[c - 'a']--;
        }
        bool possible = true;
        for (int i = 0; i < 26; i++) {
            if (alphabet[i] != 0) {
                possible = false;
                break;
            }
        }
        if (possible) {
            cout << "Possible\n";
        } else {
            cout << "Impossible\n";
        }
    }
}