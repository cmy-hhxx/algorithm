#include <iostream>

using namespace std;

const int N = 10010;
int primes[N], cnt;
bool st[N];

void get_primes()
{
    for (int i = 2; i <= N; i ++)
    {
        if (!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= N / i; j ++ )
        {
             st[primes[j] * i] = true;
             if (i % primes[j] == 0) break;
        }
    }
}

int main()
{
    
    return 0;
}
