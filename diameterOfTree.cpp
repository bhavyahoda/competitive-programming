/* To Kaise Hain Aaplog*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
vector<int> v[100001];
bool vis[100001] = {0};
int maxNode=0,maxD=0;
void dfs(int s,int d)
{
    if(d>maxD){
        maxD = d;
        maxNode = s;
    }
    vis[s] = true;
    for (int u : v[s])
    {
        if (vis[u] == false)
        {
            
            dfs(u,d+1);
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
 
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n ;
        maxD=0;
        maxNode =-1;
        for (int i = 0; i < n-1; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        dfs(0,0);
        maxD=0;
        memset(vis,false,sizeof(vis));
        dfs(maxNode,0);
        cout<<ceil((float)maxD/2)<<"\n";
        for(int i=0;i<=n;i++){
            v[i].clear();
        }
        memset(vis,false,sizeof(vis));
    }
    return 0;
}