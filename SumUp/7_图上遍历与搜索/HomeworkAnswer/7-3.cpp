/*
 * @Description: L-朋友圈
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-23 15:12:07
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-23 20:57:24
 */
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
bool mp[MAXN][MAXN];
bool vis[MAXN];
int n, m;
int ans, cnt;

int dfs(int x) {
    if (vis[x]) return 0;
    vis[x] = true;
    int rtn = 1;
    for (int i = 0; i < n; i++) {
        if (mp[x][i]) rtn += dfs(i);
    }
    return rtn;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        mp[u][v] = true;
        mp[v][u] = true;
    }
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {              // 如果某点未遍历，则其所在整个联通块都一定未遍历
            ans = max(ans, dfs(i));
            cnt++;
        }
    }
    printf("%d %d", cnt, ans);
    return 0;
}