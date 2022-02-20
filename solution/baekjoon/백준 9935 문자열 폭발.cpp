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

int main() {
    string str;
    string explosion;

    cin >> str;
    cin >> explosion;

    stack<char> mainStack;

    for (char s : str) {
        bool isNotExplosion = false;
        if (s == explosion.back()) {
            stack<char> tempStack;
            tempStack.push(s);
            for (auto k = explosion.rbegin() + 1; k != explosion.rend(); k++) {
                if (mainStack.empty()) {
                    isNotExplosion = true;
                    break;
                }

                if (*k != mainStack.top()) {
                    isNotExplosion = true;
                    break;
                }

                if (*k == mainStack.top()) {
                    tempStack.push(mainStack.top());
                    mainStack.pop();
                }
            }

            if (isNotExplosion) {
                while(!tempStack.empty()) {
                    mainStack.push(tempStack.top());
                    tempStack.pop();
                }
            }
        } else {
            mainStack.push(s);
        }
    }

    if (mainStack.empty()) {
        cout << "FRULA\n";
    } else {
        string ans;
        while (!mainStack.empty()) {
            ans.push_back(mainStack.top());
            mainStack.pop();
        }

        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }


    return 0;
}
