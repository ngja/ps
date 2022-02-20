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
typedef pair<int, int> pii;

using namespace std;

int n;
int tempAns = 0;
int rightUpLine[20];
int leftDownLine[20];

vector<pii> whitePos;
int whiteAns = 0;

vector<pii> blackPos;
int blackAns = 0;

int getRightUpLineIndex(pii& position) {
    return position.first + position.second;
}

int getLeftDownLineIndex(pii& position) {
    return position.first - position.second + n - 1;
}

void solution(vector<pii>& pos, int index, int count) {
    // 종료 조건
    if (index >= pos.size()) {
        if (tempAns < count)
            tempAns = count;
        return;
    }

    if (rightUpLine[getRightUpLineIndex(pos[index])] == 0 && leftDownLine[getLeftDownLineIndex(pos[index])] == 0) {
        rightUpLine[getRightUpLineIndex(pos[index])] = 1;
        leftDownLine[getLeftDownLineIndex(pos[index])] = 1;
        solution(pos, index + 1, count + 1);
        rightUpLine[getRightUpLineIndex(pos[index])] = 0;
        leftDownLine[getLeftDownLineIndex(pos[index])] = 0;
    }

    // 안선택
    solution(pos, index + 1, count);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) {
                if ((i+j) % 2 == 0) {
                    whitePos.emplace_back(i, j);
                } else {
                    blackPos.emplace_back(i, j);
                }
            }
        }
    }

    solution(whitePos, 0, 0);
    whiteAns = tempAns;
    tempAns = 0;
    solution(blackPos, 0, 0);
    blackAns = tempAns;

    cout << whiteAns + blackAns << "\n";

    return 0;
}
