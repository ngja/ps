#include <iostream>
#include <vector>
#include <string>
using namespace  std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

const int MAXSIZE = 16;

enum Direction {
    RIGHT,
    DOWN,
    RIGHT_DOWN
};

int house[MAXSIZE][MAXSIZE];
int n;
int ans = 0;

void move(int y, int x, Direction state) {
    if (y == n-1 && x == n-1) {
        ans++;
        return;
    }

    bool canMoveDown = y + 1 < n && house[y+1][x] == 0;
    bool canMoveRight = x + 1 < n && house[y][x+1] == 0;
    bool canMoveRightDown = canMoveDown && canMoveRight && house[y+1][x+1] == 0;

    switch (state) {
        case RIGHT:
            if (canMoveRight)
                move(y, x+1, RIGHT);
            if (canMoveRightDown)
                move(y+1, x+1, RIGHT_DOWN);
            break;
        case DOWN:
            if (canMoveDown)
                move(y+1, x, DOWN);
            if (canMoveRightDown)
                move(y+1, x+1, RIGHT_DOWN);
            break;
        case RIGHT_DOWN:
            if (canMoveRight)
                move(y, x+1, RIGHT);
            if (canMoveDown)
                move(y+1, x, DOWN);
            if (canMoveRightDown)
                move(y+1, x+1, RIGHT_DOWN);
            break;
    }
}

int main() {

    cin >> n;

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) {
            cin >> house[y][x];
        }
    }

    move(0, 1, RIGHT);

    cout << ans << "\n";


    return 0;
}
