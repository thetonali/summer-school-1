/*
 * @Description: L-马走日
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-23 14:53:05
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-23 15:11:41
 */
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 5;
int f[MAXN][MAXN];
int n, m;
int tgtX, tgtY;
int beginX, beginY;
int dir[][2] = {{+1, +2}, {-1, +2}, {+1, -2}, {-1, -2}, {+2, +1}, {+2, -1}, {-2, +1}, {-2, -1}};

inline bool overflow(int _x, int _y) { return _x < 0 || _x >= n || _y < 0 || _y >= m; }

void bfs() {
    queue<pair<int, pair<int, int> > > q;           // <steps, X, Y>
    q.push(make_pair(0, make_pair(tgtX, tgtY)));
    while (!q.empty()) {
        int s = q.front().first;
        int _x = q.front().second.first;
        int _y = q.front().second.second;
        q.pop();
        if (f[_x][_y] <= s) continue;
        f[_x][_y] = s;
        for (int i = 0; i < 8; i++) {
            int toX = _x + dir[i][0];
            int toY = _y + dir[i][1];
            if (overflow(toX, toY)) continue;
            q.push(make_pair(s + 1, make_pair(toX, toY)));
        }
    }
    return;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &beginX, &beginY);
    scanf("%d %d", &tgtX, &tgtY);

    memset(f, 0x7f, sizeof f);
    bfs();
    if (f[beginX][beginY] == 0x7f7f7f7f) putchar(48);   // 无解输出 0
    else printf("%d", f[beginX][beginY]);               // 有解输出最短步数
    return 0;
}