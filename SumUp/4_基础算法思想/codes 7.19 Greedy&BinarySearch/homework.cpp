/*
 * @Description: 赶作业 标程
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-19 16:58:27
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-19 20:05:08
 */
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1001;
struct Homework {
    int ddl;
    int scr;
    int date;
    bool done;
} works[MAXN];
int T, n;

bool cmp(Homework _a, Homework _b) {
    return _a.scr > _b.scr;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) 
            scanf("%d", &works[i].ddl);
        for (int i = 1; i <= n; i++) 
            scanf("%d", &works[i].scr);
        for (int i = 1; i <= n; i++) {
            works[i].date = 0;
            works[i].done = false;
        }
        // 从价值最大的作业开始做
        sort(works + 1, works + n + 1, cmp);
        for (int i = 1; i <= n; i++) {
            // 开大根堆记录先前安排了写作业的日子
            priority_queue<int> pq;
            for (int j = 1; j < i; j++) {
                if (!works[j].done) continue;
                if (works[j].date > works[i].ddl) continue;
                pq.push(works[j].date);
            }
            // 尽量拖延，如果当前安排的时间有作业要做，尝试安排前一天，直到无法安排
            int cur = works[i].ddl;
            while (pq.size()) {
                if (!cur) break;
                int t = pq.top();
                pq.pop();
                if (cur != t) break;
                cur--;
            }
            if (cur) {
                works[i].date = cur;
                works[i].done = true;
            }
        }
        // 求和，输出
        long long ans = 0LL;
        for (int i = 1; i <= n; i++) {
            if (!works[i].done) ans += works[i].scr;
        }
        printf("%lld\n", ans);
    }
    return 0;
}