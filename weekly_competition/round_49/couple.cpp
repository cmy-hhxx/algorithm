#include <iostream>

using namespace std;

int n, k;

int main()
{
    cin >> n >> k;

    int ans = 0;

    for (int i = 0; i < n; i ++ )
    {
        int y;
        cin >> y;
        if (y + k <= 5) ans ++;
    }

    cout << ans / 3 << endl;

    return 0;
}
