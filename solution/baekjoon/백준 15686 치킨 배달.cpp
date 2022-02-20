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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int n, m;
int world[55][55];
int ans = 987654321;

vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<int> subset;

int manhattanDistance(int y1, int x1, int y2, int x2) {
    return abs(y1-y2) + abs(x1-x2);
}

void search(int k, int count) {
    if (k == count) {
        if (subset.empty() || subset.size() > m)
            return;
        int totalDist = 0;
        for (pair<int, int> h : house) {
            int houseDist = 987654321;
            for (int s : subset) {
                int tempDist = manhattanDistance(h.first, h.second, chicken[s].first, chicken[s].second);
                if (houseDist > tempDist)
                    houseDist = tempDist;
            }
            totalDist += houseDist;
        }
        if (ans > totalDist)
            ans = totalDist;
    } else {
        subset.push_back(k);
        search(k+1, count);
        subset.pop_back();
        search(k+1, count);
    }
}

int main() {

    cin >> n >> m;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> world[i][j];
            if (world[i][j] == 2) {
                chicken.emplace_back(i, j);
            } else if (world[i][j] == 1) {
                house.emplace_back(i, j);
            }
        }
    }

    int chickenCount = chicken.size();
    search(0, chickenCount);
    cout << ans << "\n";


    return 0;
}
