#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int q[N];
int n;

void quick_sort(int l, int r)
{
    if (l == r) return ;

    int x = q[l + r >> 1], right = r + 1, left = l - 1;
    while (left < right)
    {
        do left ++; while (q[left] < x);
        do right --; while (q[right] > x);
        if (left < right) swap(q[left], q[right]);
    }
    quick_sort(l, right);
    quick_sort(right + 1, r);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    quick_sort(0, n - 1);

    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

    return 0;
}
