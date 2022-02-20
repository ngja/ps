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

int n, m;
bool chosen[10];
vector<int> num;
vector<int> idx;

void solution() {

    if (idx.size() == m) {
        for (int i : idx)
            cout << num[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (chosen[i]) continue;
        if (!idx.empty() && num[idx.back()] > num[i]) continue;

        idx.push_back(i);
        solution();
        idx.pop_back();
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        num.push_back(a);
    }

    sort(num.begin(), num.end());

    solution();


    return 0;
}
