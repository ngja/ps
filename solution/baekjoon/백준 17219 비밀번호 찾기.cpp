#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> store;
    while (n--) {
        string site, pwd;
        cin >> site >> pwd;
        store[site] = pwd;
    }

    while (m--) {
        string site;
        cin >> site;
        cout << store[site] << "\n";
    }

    return 0;
}
