#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010;
int q[N];
int n, k;

int quick_sort(int l, int r, int k)
{
    if (l == r) return q[l];

    int x = q[l + r >> 1], right = r + 1, left = l - 1;
    while (left < right)
    {
        do left ++; while (q[left] < x);
        do right --; while (q[right] > x);
        if (left < right) swap(q[left], q[right]);
    }

    int sum_left = right - l + 1;
    if (k <= sum_left) return quick_sort(l, right, k);
    else return quick_sort(right + 1, r, k - sum_left);
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

    cout << quick_sort(0, n - 1, k) << endl;

    return 0;
}
