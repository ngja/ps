#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <algorithm>
#include <tuple>
#include <bitset>
#include <cstring>
#include <queue>
using namespace  std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pi;

vii city;

int main() {

    int n;
    scanf("%d", &n);
    priority_queue<int, vector<int>> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (i==0) {
            maxHeap.push(num);
        }else if (maxHeap.size() <= minHeap.size()) {
            // minHeap에서 꺼내서 비교
            int top = minHeap.top();

            if (num > top) {
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(top);
            } else {
                maxHeap.push(num);
            }

        } else if (maxHeap.size() > minHeap.size()) {
            // maxHeap에서 꺼내서 비교
            int top = maxHeap.top();

            if (num > top) {
                minHeap.push(num);
            } else {
                maxHeap.pop();
                maxHeap.push(num);
                minHeap.push(top);
            }
        }
        printf("%d\n", maxHeap.top());
    }
    return 0;
}
