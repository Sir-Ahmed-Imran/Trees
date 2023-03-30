            ///~~~LOTA~~~///
#include <bits/stdc++.h>
using namespace std;
#define str to_string
#define in binary_search
#define ll long long
#define pointer vector<int>::iterator
#define li long int
#define ld long double
#define append push_back
#define add insert
#define nl "\n"
#define all(x) (x).begin(),(x).end()
#define sum(a) accumulate(all(a),0)
#define L0TA ios_base::sync_with_stdio(false);cin.tie(NULL)
#define terminator main
#define MAXN 200001
vector<int> a[MAXN];
int pa[MAXN];
int sz[MAXN];
bool v[MAXN];
int find_size(int q, int p = -1) {
  if (v[q]) return 0;
  sz[q] = 1;
  for (auto& x:a[q]){
    if (x != p) sz[q] += find_size(x, q);
  }
  return sz[q];
}
int find_centroid(int n,int m,int o){
    for(auto& i:a[n]){
        if(i==m || v[i] || sz[i]<=o/2) continue;
        return find_centroid(i,n,o);
    }
    return n;
}
void centroid(int n=1, int p=-1) {
  find_size(n);
  int q = find_centroid(n, -1, sz[n]);
  v[q] = true;
  pa[q] = p;
  for (int x: a[q]) {
    if (!v[x]) {
      centroid(x, q);
    }
  }
}
int terminator(){
    L0TA;
    int n,m,o,p,q,r,s;
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>p>>q;
        a[p].append(q);
        a[q].append(p);
    }
    centroid();
    return 0;
}
