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

using namespace std;

const int INF = ~(1 << 31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n, m;
vector<int> num;
vector<int> sub;
bool chosen[10];

void solution() {

    if (sub.size() == m) {
        for (int idx : sub)
            printf("%d ", num[idx]);
        printf("\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        if (chosen[i]) continue;
        chosen[i] = true;
        sub.push_back(i);
        solution();
        chosen[i] = false;
        sub.pop_back();
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    sort(num.begin(), num.end());

    solution();

    return 0;
}
