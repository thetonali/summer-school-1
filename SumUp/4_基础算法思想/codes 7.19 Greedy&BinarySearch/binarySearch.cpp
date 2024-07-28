# include <bits/stdc++.h>
using namespace std;

const int MAXN = (int)1e6;
int a[MAXN];
int n, m;

int search(int _k) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] >= _k) r = mid;
        else l = mid + 1;
    }
    return l - 1;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) {
        int k;
        scanf("%d", &k);
        if (i == 1) printf("%d", search(k));
        else printf(" %d", search(k));
    }
    return 0;
}