/*
 * @Description: 八皇后问题
 * @Author: Duawieh
 * @Email: DuawiehPublic@outlook.com
 * @Date: 2024-07-23 16:57:09
 * @LastEditors: Duawieh
 * @LastEditTime: 2024-07-23 17:07:38
 */
# include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
bool used[10];
int ans[MAXN];
int n, k;
int cnt;

// 检验八皇后解的合法性
inline bool check(int _state) {
    int pos[10];
    for (int i = 0; i < 8; i++) {
        pos[i] = _state % 10;
        _state /= 10;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < i; j++) {
            if (pos[i] == pos[j]) return false;
            if ((pos[i] - pos[j]) == (i - j)) return false;
            if ((pos[i] - pos[j]) == (j - i)) return false;
        }
    }

    return true;
}

// 深度优先搜索枚举可能的解（枚举集合包含所有合法解但大于合法解集）
void init(int _len, int _state) {
    if (_len == 8) {
        if (check(_state)) ans[++cnt] = _state;
        return;
    }
    for (int i = 1; i <= 8; i++) {
        if (used[i]) continue;
        used[i] = true;
        init(_len + 1, _state * 10 + i);
        used[i] = false;
    }
    return;
}

int main() {
    init(0, 0);
    sort(ans + 1, ans + cnt + 1);
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
    return 0;
}