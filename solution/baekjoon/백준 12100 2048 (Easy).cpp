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

const int INF = 2000000000;
const ll LL_INF = 10000000000LL;

vector<int> directions; // 0: 아래, 1: 오른쪽, 2: 위쪽, 3: 왼쪽

int n;
int initialBoard[21][21];
int ans = 0;

void dfs() {

    if (directions.size() == 5) {

        int copyBoard[21][21];

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                copyBoard[i][j] = initialBoard[i][j];
            }
        }


        for(int i = 0; i < 5; i++) {

            for (int j = 0; j < n; ++j) {
                stack<int> s;
                queue<int> q;

                for (int k = 0; k < n; ++k) {
                    pair<int, int> target;

                    if (directions[i] == 0) {
                        target = {k, j};
                    } else if (directions[i] == 1) {
                        target = {j, k};
                    } else if (directions[i] == 2) {
                        target = {n - k - 1, j};
                    } else {
                        target = {j, n - k - 1};
                    }

                    if (copyBoard[target.first][target.second] == 0)
                        continue;
                    s.push(copyBoard[target.first][target.second]);
                }

                if (s.empty()) {
                    continue;
                }

                // stack에 옮겨진 결과값 저장
                int left = 0;
                int right = 0;

                while (!s.empty()) {
                    if (left == 0) {
                        left = s.top();
                        s.pop();
                        continue;
                    }

                    right = s.top();
                    s.pop();

                    if (left == right) {
                        q.push(left + right);
                        left = 0;
                        right = 0;
                    } else {
                        q.push(left);
                        left = right;
                        right = 0;
                    }
                }

                if (left != 0) {
                    q.push(left);
                }

                // queue에 있는거 위치로 이동
                for (int k = 0; k < n; ++k) {
                    pair<int, int> target;

                    if (directions[i] == 0) {
                        target = {n - k - 1, j};
                    } else if (directions[i] == 1) {
                        target = {j, n - k - 1};
                    } else if (directions[i] == 2) {
                        target = {k, j};
                    } else {
                        target = {j, k};
                    }

                    int value = 0;
                    if (!q.empty()) {
                        value = q.front();
                        q.pop();
                    }

                    copyBoard[target.first][target.second] = value;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, copyBoard[i][j]);
            }
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        directions.push_back(i);
        dfs();
        directions.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> initialBoard[i][j];
        }
    }

    dfs();

    cout << ans << "\n";

    return 0;
}