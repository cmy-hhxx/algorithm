#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
    int n, m;
    cin >> n;

    int a = INF, b = -INF;
    while (n -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        a = min(a, r);
        b = max(b, l);
    }

    cin >> m;
    int res = 0;
    while (m -- )
    {
        int l, r;
        scanf("%d%d", &l, &r);
        if (r < b) res = max(res, b - r);
        if (l > a) res = max(res, l - a);
    }
    printf("%d\n", res);

    return 0;
}
