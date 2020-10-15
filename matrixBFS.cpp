/* To Kaise Hain Aaplog*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;

char v[1001][1001];
int vis[1001][1001] = {0};

int rpath[] = {1, -1, 0, 0};
int cpath[] = {0, 0, 1, -1};

void reset()
{
    memset(vis, 0, sizeof(vis));
    memset(v, 0, sizeof(v));
}
bool check(int ci, int cj, int n, int m)
{
    if (ci >= 0 && cj >= 0 && ci < n && cj < m && v[ci][cj] != '.')
    {
        return true;
    }

    return false;
}

void bfs(int a, int b, int n, int m)
{
    vis[a][b] = 1;
    queue<int> rq;
    queue<int> cq;
    rq.push(a);
    cq.push(b);
    while (!rq.empty() && !cq.empty())
    {
        int curri = rq.front();
        int currj = cq.front();
        rq.pop();
        cq.pop();
        for (int i = 0; i < 4; i++)
        {
            int ci = curri + rpath[i];
            int cj = currj + cpath[i];
            if (check(ci, cj, n, m) && vis[ci][cj] == 0)
            {
                vis[ci][cj] = 1;
                rq.push(ci);
                cq.push(cj);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    reset();
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == '#' && vis[i][j] == 0)
            {
                count++;
                bfs(i, j, n, m);
            }
        }
    }
    cout << count << "\n";

    return 0;
}
