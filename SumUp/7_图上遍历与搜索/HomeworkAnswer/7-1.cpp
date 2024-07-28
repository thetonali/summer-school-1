/*
 * @Description: 联通块的权
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-23 14:52:28
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-23 20:55:52
 */
# include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e3 + 10;
bool vis[MAXN][MAXN];
int a[MAXN][MAXN];
int T, n, m;
int ans;
pair<int, int> dir[] = {
    make_pair(0, +1),
    make_pair(0, -1),
    make_pair(+1, 0),
    make_pair(-1, 0)
};

pair<int, int> add(pair<int, int> _a, pair<int, int> _b) {
    return make_pair(_a.first + _b.first, _a.second + _b.second);
}

int bfs(int _beginX, int _beginY) {
    int rtn = 0;
    queue<pair<int, int> > q;
    q.push(make_pair(_beginX, _beginY));
    while (q.size()) {
        auto p = q.front();
        int _x = p.first;
        int _y = p.second;
        q.pop();
        if (!a[_x][_y]) continue;
        if (vis[_x][_y]) continue;
        vis[_x][_y] = true;
        rtn += a[_x][_y];
        for (int mal = 0; mal < 4; mal++) {
            pair<int, int> newP = add(p, dir[mal]);
            q.push(newP);
        }
    }
    return rtn;
}

int main() {
    scanf("%d", &T);
    while (T--) {
        ans = 0;
        memset(a, 0x00, sizeof a);
        memset(vis, 0x00, sizeof vis);
        
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!a[i][j]) continue;
                if (!vis[i][j]) ans = max(ans, bfs(i, j));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}