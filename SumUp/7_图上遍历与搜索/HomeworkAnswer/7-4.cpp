/*
 * @Description: C.光阴逝如梭
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-23 15:17:33
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-23 20:59:40
 */
# include <bits/stdc++.h>
using namespace std;

int chNum[2];
int a, k;
long long ans = 1e18;

void getChoices() {
    bool num[10] = {false};
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int c;
        scanf("%d", &c);
        num[c] = true;
    }
    for (int i = 0; i < 10; i++) {
        if (!num[i]) chNum[cnt++] = i;
    }
    return;
}

long long bfs() {
    queue<long long> q;
    q.push(0LL);
    while (q.size()) {
        long long cur = q.front();
        q.pop();
        if (cur) {
            if (cur % a == 0) return cur;   // 用广搜找到的第一个合法解即全局最优解
        }
        q.push(cur * 10 + chNum[0]);        // 优先将字典序较小的字符加入
        q.push(cur * 10 + chNum[1]);
    }
    return 0xffffffffffffffff;
}

int main() {
    scanf("%d %d", &a, &k);
    getChoices();
    bfs();
    printf("%lld", bfs());
    return 0;
}