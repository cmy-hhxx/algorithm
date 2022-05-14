#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long LL;
const int N = 210;
int n, k, m;
LL f[N][N];

int main()
{
    cin >> n >> k >> m;

    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 1; i <= n; i ++ )
    {
        int v;
        scanf("%d", &v);

        for (int j = 1; j <= m; j ++ )
        {
            for (int u = max(i -k, 0); u < i; u ++ )
                f[i][j] = max(f[i][j], f[u][j - 1] + v);
        }
    }
    LL res = -1;
    for (int i = n - k + 1; i <= n; i ++ ) res = max(res, f[i][m]);
    
    printf("%lld\n", res);

    return 0;
}
