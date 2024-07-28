/*
 * @Description: 合并果子 标程
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-19 10:22:35
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-19 10:26:56
 */
# include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)3e4 + 10;
priority_queue<int> pq;
int n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int k;
        scanf("%d", &k);
        pq.push(-k);
    }
    int ans = 0;
    while (pq.size() > 1) {
        int x1 = -pq.top();
        pq.pop();
        int x2 = -pq.top();
        pq.pop();
        ans += x1 + x2;
        pq.push(-x1 - x2);
    }
    printf("%d", ans);
    return 0;
}