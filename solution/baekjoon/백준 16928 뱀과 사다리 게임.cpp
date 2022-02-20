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
bool visited[101];

int main() {

    cin >> n >> m;

    unordered_map<int, int> ladder;
    unordered_map<int, int> snake;

    int departure, destination;
    for (int i = 0; i < n; ++i) {
        cin >> departure >> destination;
        ladder[departure] = destination;
    }

    for (int i = 0; i < m; ++i) {
        cin >> departure >> destination;
        snake[departure] = destination;
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    if (ladder[1] != 0) {
        q.push(ladder[1]);
        visited[ladder[1]] = true;
    }
    int len = 0;

    while(!q.empty()) {
        int qSize = q.size();

        len++;
        for (int i = 0; i < qSize; ++i) {
            int cur = q.front();
            q.pop();

            for (int j = 1; j <= 6; ++j) {
                if (cur + j <= 100 && !visited[cur+j]) {
                    visited[cur+j] = true;

                    if (ladder[cur+j] != 0) {
                        q.push(ladder[cur+j]);
                        visited[ladder[cur+j]] = true;
                        continue;
                    }

                    if (snake[cur+j] != 0) {
                        q.push(snake[cur+j]);
                        visited[snake[cur+j]] = true;
                        continue;
                    }

                    if (cur+j == 100) {
                        cout << len << "\n";
                        return 0;
                    }

                    q.push(cur+j);
                }
            }
        }
    }

    return 0;
}
