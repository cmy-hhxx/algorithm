#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 300010, M = N *2, mod = 998244353;
int h[N], e[M], ne[M], idx;
int s1, s2;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int color[N];
int pow2(int k)
{
    int res = 1;
    while (k --) res = res * 2 % mod;
    return res;
}

bool dfs(int u, int c)
{
    color[u] = c;
    if (c == 1) s1 ++;
    else s2 ++;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!color[j] && !dfs(j, 3 - c)) return false;
        if (color[j] == c) return false;
    }
    return true;
}
int main()
{
    int T;
    cin >> T;
    while (T -- )
    {
        int n, m;
        scanf("%d%d", &n, &m);
        memset(h, -1, (n + 1) * 4);
        memset(color, 0, (n + 1) * 4);

        while (m -- )
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }

        long long res = 1;
        for (int i = 1; i <= n; i ++ )
        {
            if (!color[i])
            {
                s1 = s2 = 0;
                if (dfs(i, 1)) res = (long long) res * (pow2(s1) + pow2(s2)) % mod;
                else
                {
                    res = 0;
                    break;
                }
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
