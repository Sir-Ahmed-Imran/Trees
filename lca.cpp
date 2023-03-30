            ///~~~LOTA~~~///
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
#define li long int
#define ld long double
#define append push_back
#define add insert
#define nl "\n"
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define sum(a) accumulate(all(a),0)
#define L0TA ios_base::sync_with_stdio(false);cin.tie(NULL)
#define terminator main
#define MAXN 100001
#define level 18
vector <int> tree[MAXN];
int depth[MAXN];
int parent[MAXN][level];
void dfs(int cur, int prev){
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;
    for (int i=0; i<tree[cur].size(); i++){
        if (tree[cur][i] == prev) continue;
        dfs(tree[cur][i], cur);
    }
}
void precomputeSparseMatrix(int n){
    for (int i=1; i<level; i++){
        for (int node = 1; node <= n; node++){
            if (parent[node][i-1] != -1)
                parent[node][i] = parent[parent[node][i-1]][i-1];
        }
    }
}
int lca(int u, int v){
    if (depth[v] < depth[u])
        swap(u, v);
 
    int diff = depth[v] - depth[u];
    for (int i=0; i<level; i++)
        if ((diff>>i)&1)
            v = parent[v][i];
    if (u == v)
        return u;
    for (int i=level-1; i>=0; i--)
        if (parent[u][i] != parent[v][i]){
            u = parent[u][i];
            v = parent[v][i];
        }
    return parent[u][0];
}
void addEdge(int u,int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
}
int dist(int u, int v, int k){
    return depth[v]+depth[u]-2*depth[k];
}
int terminator(){
    L0TA;
    bool r;
    int n,m,o,p,q,x;
    cin>>n;
    memset(parent,-1,sizeof(parent));
    for(int i=1;i<n;i++){
        cin>>p>>q;
        addEdge(p,q);
    }
    depth[0] = 0;
    dfs(1,0);
    precomputeSparseMatrix(n);
    return 0;
}
