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
using namespace  std;

const int INF = ~(1<<31);
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

int lcs[1005][1005] = { 0, };

int main() {

    string input1;
    string input2;

    cin >> input1;
    cin >> input2;

    for (int i = 0; i < input1.length(); i++) {
        for (int j = 0; j < input2.length(); j++) {
            if (input1[i] == input2[j]) {
                lcs[i+1][j+1] = lcs[i][j] + 1;
            } else {
                lcs[i+1][j+1] = max(lcs[i][j+1], lcs[i+1][j]);
            }
        }
    }

    int len = lcs[input1.length()][input2.length()];

    string word;

    int y = input1.length();
    int x = input2.length();


    while(true) {
        if (lcs[y][x] == 0)
            break;

        if (lcs[y][x] == lcs[y][x-1]) {
            x--;
        } else if (lcs[y][x] == lcs[y-1][x]) {
            y--;
        } else {
            word += input1[y-1];
            y--;
            x--;
        }
    }

    reverse(word.begin(), word.end());

    cout << len << "\n";

    if (word.length() != 0)
        cout << word << "\n";

    return 0;
}
