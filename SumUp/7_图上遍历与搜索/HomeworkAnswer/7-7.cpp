/*
 * @Description: Nightmare II
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-23 20:52:23
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-23 21:05:06
 */
#include<bits/stdc++.h>
using namespace std;

const int maxn = 805;
char g[maxn][maxn];
queue<pair<int, pair<int, int> > > q[2];
pair<int, int> gst[2];
bool vis[2][maxn][maxn];
int n, m, t, goast_cnt;

inline char check(bool c, bool st, int x, int y, int lmt) {
    if (x < 1 || x > n || y < 1 || y > m) return 0;
    if (!st && vis[c][x][y] || g[x][y] == 'X') return 0;
    if (abs(x - gst[1].first) + abs(y - gst[1].second) <= lmt << 1) return 0;
    if (abs(x - gst[0].first) + abs(y - gst[0].second) <= lmt << 1) return 0;
    if (vis[!c][x][y]) return 2;
    return 1;
}

/// @brief 每秒用广搜扩展和检验相遇
/// @param c 所用队列、颜色序号
/// @param lmt 当前秒数（用于计算步数限制）
/// @return 当前一秒是否相遇
bool Augment(bool c, int lmt) {
    int stp_lmt = lmt * (!c * 2 + 1);
    char check_result;
    while (q[c].size())
        if (q[c].front().first < stp_lmt) {
            int s = q[c].front().first;
            int x = q[c].front().second.first;
            int y = q[c].front().second.second;
            q[c].pop();
            check_result = check(c, true, x, y, lmt);
            if (check_result) {
                if (check_result == 2) return true;
                vis[c][x][y] = true;

                check_result = check(c, false, x + 1, y, lmt);
                if (check_result) {
                    vis[c][x + 1][y] = true;
                    if (check_result == 2) return true;
                    q[c].push(make_pair(s + 1, make_pair(x + 1, y)));
                }
                check_result = check(c, false, x - 1, y, lmt);
                if (check_result) {
                    vis[c][x - 1][y] = true;
                    if (check_result == 2) return true;
                    q[c].push(make_pair(s + 1, make_pair(x - 1, y)));
                }
                check_result = check(c, false, x, y + 1, lmt);
                if (check_result) {
                    vis[c][x][y + 1] = true;
                    if (check_result == 2) return true;
                    q[c].push(make_pair(s + 1, make_pair(x, y + 1)));
                }
                check_result = check(c, false, x, y - 1, lmt);
                if (check_result) {
                    vis[c][x][y - 1] = true;
                    if (check_result == 2) return true;
                    q[c].push(make_pair(s + 1, make_pair(x, y - 1)));
                }
            }
        } else break;
    return false;
}

// 逐秒分别调用广度优先搜索进行答案检验，内部用具体的广搜实现检验
int bfs() {
    int ans = 0;
    while (q[0].size() && q[1].size()) {
        ans += 1;
        if (Augment(0, ans)) return ans;
        if (Augment(1, ans)) return ans;
    }
    return -1;
}

int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++) {
            getchar();
            for (int j = 1; j <= m; j++) {
                g[i][j] = getchar();
                if (g[i][j] == 'M') q[0].push(make_pair(0, make_pair(i, j)));
                if (g[i][j] == 'G') q[1].push(make_pair(0, make_pair(i, j)));
                if (g[i][j] == 'Z') { gst[++goast_cnt & 1].first = i; gst[goast_cnt & 1].second = j; }
            }
        }

        printf("%d\n", bfs());

        memset(vis, 0x00, sizeof(vis));
        while (q[0].size()) q[0].pop();
        while (q[1].size()) q[1].pop();
    }
    return 0;
}