# include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e5 + 10;
int a[MAXN];
int n, c;

inline bool check(int _k) {
    int dis = 0;
    int cnt = 1;
    for (int i = 2; i <= n; i++) {
        dis += a[i] - a[i - 1];
        if (dis >= _k) {
            cnt++;
            dis = 0;
        }
    }
    return cnt >= c;
}

int main() {
    scanf("%d %d", &n, &c);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = ceil((l + r) / 2.0);
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    printf("%d", l);
    return 0;
}