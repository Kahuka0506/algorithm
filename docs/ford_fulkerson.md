# ford_fulkerson
リンク : [../graph/ford_fulkerson.cpp](../graph/ford_fulkerson.cpp)    
最終更新 : 2021-10-26 13:35:29.465941

```cpp

template <typename T>
class FordFulkerson {
    int n;
    ve<ve<pair<int,pair<T,int>>>> g;
    ve<bool> used;
    
public:
    FordFulkerson(int n_, ve<ve<pair<int,T>>>& G):n(n_){
        g.resize(n);
        used.resize(n);
        
        rep(i,n){
            for (auto p : G[i]) {
                g[i].pb({p.fi,{p.se,si(g[p.fi])}});
                g[p.fi].pb({i,{0,si(g[i])-1}});
            }
        }
    }
    
    T dfs(int v, int t, T f){
        if(v == t) return f;
        used[v] = true;
        
        for (auto& p : g[v]) {
            if(used[p.fi] || p.se.fi <= 0) continue;
        
            T d = dfs(p.fi, t, min(f, p.se.fi));
            if(d > 0){
                p.se.fi -= d;
                g[p.fi][p.se.se].se.fi += d;
                return d;
            }
        }
        
        return 0;
    }
    
    T max_flow(int s, int t){
        T flow = 0;
        while (1) {
            used.assign(n,false);
            T f = dfs(s,t,infi);
            if(f == 0) return flow;
            
            flow += f;
        }
    }
};
```