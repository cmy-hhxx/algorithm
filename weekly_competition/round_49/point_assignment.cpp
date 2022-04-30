#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 300010, M = N * 2, mod = 998244353;
int h[N], e[M], ne[M], idx;
int n, m;
int col[N];
int s1, s2;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int pow2(int k)
{
    int res = 1;
    while (k -- ) res = res * 2 % mod;
    return res;
}

bool dfs(int u, int c)
{
    col[u] = c;
    if (c == 1) s1 ++;
    else s2 ++;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (col[j] && col[j] != 3 - c) return false;
        if (!col[j] && !dfs(j, 3 - c)) return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;

    while (T --)
    {
        scanf("%d%d", &n, &m);
        memset(h, -1, (n + 1) * 4);
        memset(col, 0, (n + 1) * 4);
        idx = 0;

        while (m -- )
        {
            int a, b;
            scanf("%d%d", &a, &b);
            add(a, b), add(b, a);
        }
        int res = 1;
        for (int i = 1; i <= n; i ++ )
        {
            if (!col[i])
            {
                s1 = s2 = 0;
                if (dfs(i, 1)) res = (LL) res * (pow2(s1) + pow2(s2)) % mod;
                else
                {
                    res = 0;
                    break;
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}
