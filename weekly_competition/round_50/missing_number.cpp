#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
bool st[N];
int n;

int main()
{
    cin >> n;

    for (int i = 1; i < n; i ++)
    {
        int x;
        cin >> x;
        st[x] = true;
    }

    for (int i = 1; i <= n; i ++)
        if (!st[i]) cout << i << endl;

    return 0;
}
