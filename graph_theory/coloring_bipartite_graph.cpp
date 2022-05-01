#include <iostream>
#include <cstring>

using namespace std;

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
int color[N];
int n, m;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c)
{
    color[u] = c;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!color[j])
        {
            if (!dfs(j, 3 - c)) return false;
        }
        else if (color[j] == c) return false;
    }
    return true;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;

    while (m --)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    bool flag = false;
    for (int i = 1; i <= n; i ++ )
    {
        if (!color[i])
        {
            if (!dfs(i, 1))
            {
                flag = true;
                break;
            }
        }
    }

    if (flag) printf("No\n");
    else printf("Yes\n");
    return 0;
}
