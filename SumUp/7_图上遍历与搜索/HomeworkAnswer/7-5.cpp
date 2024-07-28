# include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 10;
int f[MAXN << 1];
int n, k;
int ans;

// 深搜做法待优化，暂时无法满分通过
int dfs(int x, int s) {
    if (s >= f[x]) return ans;
    if (s >= ans) return ans;
    if (x <= 0) return ans;
    f[x] = min(f[x], s);
    if (x >= k) return ans = min(ans, x - k + s);
    return min(dfs(x * 2, s + 1), min(dfs(x + 1, s + 1), dfs(x - 1, s + 1)));
}

// 广搜 + 记忆化 可正常通过此题
void bfs() {
    queue<pair<int, int> > q;
    q.push(make_pair(0, n));
    while (q.size()) {
        int s = q.front().first;
        int x = q.front().second;
        q.pop();
        if (x <= 0) continue;
        if (s >= ans) continue;
        if (s >= f[x]) continue;
        f[x] = s;
        if (x >= k) { ans = min(ans, x - k + s); continue; }
        q.push(make_pair(s + 1, x * 2));
        q.push(make_pair(s + 1, x + 1));
        q.push(make_pair(s + 1, x - 1));
    }
    return;
}

int main() {
    memset(f, 0x7f, sizeof f);
    scanf("%d %d", &n, &k);
    ans = abs(k - n);
    // printf("%d", dfs(n, 0));
    bfs();
    printf("%d", ans);
    return 0;
}