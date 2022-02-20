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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n;
int population[11];
int color[11]; // 1 -> red, 0 -> blue
vector<vi> city;
bool visited[11];
set<int> red;
set<int> blue;
int redBegin;
int blueBegin;

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    if (color[s] == 1)
        red.insert(s);
    else
        blue.insert(s);
    for (auto k : city[s]) {
        if (color[s] == color[k])
            dfs(k);
    }
}

int main() {
    
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> population[i];

    city.assign(n+1, vector<int>());

    for (int i = 1; i <= n; ++i) {
        int e;
        cin >> e;
        for (int j = 0; j < e; ++j) {
            int v;
            cin >> v;
            city[i].push_back(v);
        }
    }

    // 모든 케이스 확인
    int ans = INF;
    for (int i = 1; i < (1<<n)-1; i++) {
        for (int j = 0; j < n; j++) {
            if (i&(1<<j)) {
                color[j+1] = 1;
                redBegin = (j+1);
            }
            else {
                color[j+1] = 0;
                blueBegin = (j+1);
            }
        }

        for (int j = 1; j <= 10; ++j)
            visited[j] = false;
        red.clear();
        blue.clear();

        dfs(redBegin);
        dfs(blueBegin);

        if (!red.empty() && !blue.empty() && red.size() + blue.size() == n) {
            int redSum = 0;
            for (int a : red)
                redSum += population[a];
            int blueSum = 0;
            for (int b : blue)
                blueSum += population[b];

            int tempAns = abs(redSum - blueSum);
            if (ans > tempAns)
                ans = tempAns;
        }
    }

    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << "\n";

    return 0;
}
