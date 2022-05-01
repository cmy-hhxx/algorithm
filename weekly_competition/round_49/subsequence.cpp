#include <iostream>

using namespace std;

const int N = 100010;
int q[N];
int f[N][2];
int n;

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i ++ ) scanf("%d", &q[i]);

    f[0][0] = -2e9;

    for (int i = 1; i <= n; i ++ )
    {
        f[i][0] = f[i - 1][0];
        f[i][1] = f[i - 1][1];

        if (q[i] % 2)
        {
            f[i][0] = max(f[i][0], f[i - 1][1] + q[i]);
            f[i][1] = max(f[i][1], f[i - 1][0] + q[i]);
        }
        else
        {
            f[i][0] = max(f[i][0], f[i - 1][0] + q[i]);
            f[i][1] = max(f[i][1], f[i - 1][1] + q[i]);
        }
    }

    int ans = -2e9;
    for (int i = 1; i <= n; i ++ ) ans = max(ans, f[i][0]);

    cout << ans << endl;

    return 0;
}
