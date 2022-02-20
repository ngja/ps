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

bool valid[1000001];
int main() {

    int t;
    cin >> t;


    while(t--) {
        int n;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> lpq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<>> gpq;

        cin >> n;
        for (int i = 0; i < n; ++i) {
            valid[i] = false;
        }

        char cmd;
        int num;
        for (int i = 0; i < n; ++i) {
            cin >> cmd >> num;

            if (cmd == 'I') {
                lpq.push({num, i});
                gpq.push({num, i});
            } else if (cmd == 'D') {
                if (num == 1) {
                    while(!gpq.empty()) {
                        pair<int, int> top = gpq.top();
                        gpq.pop();

                        if (gpq.empty() || !valid[top.second]) {
                            valid[top.second] = true;
                            break;
                        }
                    }
                } else if (num == -1) {
                    while(!lpq.empty()) {
                        pair<int, int> top = lpq.top();
                        lpq.pop();

                        if (lpq.empty() || !valid[top.second]) {
                            valid[top.second] = true;
                            break;
                        }
                    }
                }
            }
        }

        while(!gpq.empty()) {
            if (valid[gpq.top().second]) {
                gpq.pop();
            } else {
                break;
            }
        }

        while (!lpq.empty()) {
            if (valid[lpq.top().second]) {
                lpq.pop();
            } else {
                break;
            }
        }

        if (gpq.empty() || lpq.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << gpq.top().first << " " << lpq.top().first << "\n";
        }
    }




    return 0;
}
