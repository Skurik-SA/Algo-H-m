#include <iostream>
#include <cstdio>
#include <algorithm>
#define lb(x) (x & (-x))

using namespace std;

const int MAXN = 100000 + 5;
typedef long long ll;

int n, m;
ll x[MAXN];
int p[MAXN];

struct task {
    int nom, t;
    ll w, f;
};

task t[MAXN];

bool cmp1(task a, task b) { return a.f < b.f; }
bool cmp2(task a, task b) { return a.t > b.t; }

int sz;
int it[MAXN];

void update(int t) {
    while(t <= sz) it[t]++, t += lb(t);
    }

int qu(int t) {
    int ans = 0;
    while(t) ans += it[t],
             t -= lb(t);
    return ans;
    }

int query(int l, int r) { if(l > r) return 0;
                          return qu(r) - qu(l - 1); }

int main() {
    int i, k, d;

    scanf("%d%d", &n, &m);
    for(i=1; i<=m; i++) scanf("%d", &t[i].t);
    for(i=1; i<=n; i++) {
        scanf("%d", &k);
        while(k--) {
            scanf("%d", &d);
            x[i] += ll(t[d].t),
            p[d] = i;
            }
        }

    for(i=1; i<=m; i++) t[i].w = x[p[i]],
                        t[i].f = t[i].w - t[i].t;

    sort(t + 1, t + m + 1, cmp1);

    t[1].nom = 1;
    for(i=2; i<=m; i++)
    if(t[i].f != t[i - 1].f) t[i].nom = t[i - 1].nom + 1;
    else t[i].nom = t[i - 1].nom;

    sz = t[m].nom;

    sort(t + 1, t + m + 1, cmp2);
    ll ans = 0;

    int l, r;
    int j;
    l = r = 1;

    for(i=2; i<=m; i++)
        {
        if(t[i].t != t[i - 1].t) { for(j=l; j<=r; j++) update(t[j].nom); l = i; }
        r = i;
        ans += ll(query(t[i].nom + 1, sz));
        }

    printf("%lld\n", ans);
    return 0;
}