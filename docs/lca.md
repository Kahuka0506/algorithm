# lca
リンク : [../tree/lca.cpp](../tree/lca.cpp)    
最終更新 : 2022-10-07 22:40:36.827245

```cpp


class LCA {
    int N,M;
    vvi G;
public:
    vi d;
    vvi par;
    LCA(int n_):N(n_){G.resize(N);}
    LCA(int n_, vvi &g):N(n_){G = g;}
    void add_edge(int u, int v){G[u].pb(v);}
    void solve(int s = 0){
        M = 1;
        int c = 1;
        while(c*2 <= N) c*=2, M++;
        par.assign(M,vi(N,-1));
        d.assign(N,-1);
        d[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : G[u]) {
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                par[0][v] = u;
                que.push(v);
            }
        }
        reps(i,1,M){
            rep(j,N) if(par[i-1][j] != -1){
                par[i][j] = par[i-1][par[i-1][j]];
            }
        }
    }
    
    int find(int u, int v){
        if(d[u] < d[v]) swap(u,v);
        rep(i,M) if((d[u]-d[v]) & 1<<i) u = par[i][u];
        if(u == v) return u;
        per(i,M){
            if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }
    int level_ancestor(int u, int k){
        if(d[u] < k) return -1;
        rep(i,M) if(k&1<<i) {
            u = par[i][u];
        }
        return u;
    }
    int distance(int s, int t){
        int m = find(s,t);
        return d[s]+d[t]-2*d[m];
    }
};


 
```