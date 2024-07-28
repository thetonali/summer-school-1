# include <bits/stdc++.h>
# define int long long
using namespace std;

const int MAXN = (int)1e6;
int a[MAXN];
int n, m;

int ask(int _k) {
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r) / 2;
        if (a[mid] < _k) l = mid + 1;
        else r = mid;
    }
    return l;
}

signed main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    
    int ak;
    scanf("%lld", &ak);
    printf("%lld", ask(ak) - 1);
    
    for (int i = 2; i <= m; i++) {
        int k;
        scanf("%lld", &k);
        printf(" %lld", ask(k) - 1);
    }
    return 0;
}