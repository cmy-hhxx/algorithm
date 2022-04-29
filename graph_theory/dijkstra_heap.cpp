#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int, int> PII;

const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int n, m;

void dijkstra(int start)
{
    memset(dist, 0x3f, sizeof dist);

    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});

    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) dist[n] = -1;
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;

    while (m -- )
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    dijkstra(1);

    cout << dist[n] << endl;

    return 0;
}
