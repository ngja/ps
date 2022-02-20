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

int snakeMap[101][101]; // 0 empty, 1 snake, 2, apple

int n; // 맵 크기
int k; // 사과
int m; // 이동
vector<pair<int, int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 방향 0, 1, 2, 3 (위 오른쪽 아래 왼쪽)
char movingPlan[10001];

struct Snake {
    pair<int, int> pos;
    int time;
    int dir;
    
    int move() {
        int result = 0;

        if (movingPlan[this->time] == 'L') {
            this->dir = this->dir - 1;

            if (this->dir < 0) {
                this->dir += 4;
            }

        } else if (movingPlan[this->time] == 'D') {
            this->dir = this->dir + 1;

            if (this->dir > 3) {
                this-> dir -= 4;
            }
        }

        // 이동
        this->time += 1;
        int nextY = this->pos.first + dirs[this->dir].first;
        int nextX = this->pos.second + dirs[this->dir].second;

        if (nextY > n || nextX > n || nextY <= 0 || nextX <= 0) {
            return 1;
        }

        if (snakeMap[nextY][nextX] == 1) {
            return 1;
        }

        if (snakeMap[nextY][nextX] == 2) {
            result = 2;
        }

        snakeMap[this->pos.first][this->pos.second] = 0;
        snakeMap[nextY][nextX] = 1;
        this->pos = {nextY, nextX};

        return result;
    }
};

int main() {

    cin >> n;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        snakeMap[a][b] = 2;
    }

    cin >> m;
    for (int i = 0; i < m; ++i) {
        int a;
        char b;
        cin >> a >> b;
        movingPlan[a] = b;
    }

    snakeMap[1][1] = 1;
    vector<Snake> snake;
    snake.push_back( {{1, 1}, 0, 1});
    
    int time = 0;
    while(true) {
        int end = 0;
        int lastY = snake.back().pos.first;
        int lastX = snake.back().pos.second;
        int lastTime = snake.back().time;
        int lastDir = snake.back().dir;

        time++;
        for (Snake &s : snake) {


            int result = s.move();

            if (result == 1) {
                end = 1;
                break;
            } else if (result == 2) {
                end = 2;
            }

        }

        if (end == 1) {
            break;
        } else if (end == 2) {
            snakeMap[lastY][lastX] = 1;
            snake.push_back({{lastY, lastX}, lastTime, lastDir});
        }
    }

    cout << time << "\n";
    
    return 0;
}