
class SCC {
    int N;
    
public:
    vvi G,rG;
    ve<bool> used;
    vi cmp,vis;
    int n_scc = 0;
    
    SCC(int n){
        N = n;
        G.resize(N);
        rG.resize(N);
        cmp.resize(N);
    }
    
    
    void dfs(int n){
        used[n] = 1;
        for (int v : G[n]) {
            if(!used[v]) dfs(v);
        }
        vis.pb(n);
    }
    
    void rdfs(int n, int k){
        used[n] = 1;
        cmp[n] = k;
        for (int v : rG[n]) {
            if(!used[v]) rdfs(v,k);
        }
    }
    
    
    void solve(){
        used.assign(N,0);
        vis.clear();
        rep(i,N) if(!used[i]) dfs(i);
        
        used.assign(N,0);
        int k = 0;
        per(i,si(vis)) if(!used[vis[i]]){
            rdfs(vis[i], k++);
        }
        n_scc = k;
    }
    
    
    vvi create_dag(){
        vvi g(n_scc);
        rep(i,N){
            for (int p : G[i]) {
                if(cmp[i] != cmp[p]) g[cmp[i]].pb(cmp[p]);
            }
        }
        rep(i,n_scc){
            vi gg;
            rep(j,si(g[i])){
                if(gg.empty()) gg.pb(g[i][j]);
                else{
                    if(gg.back() == g[i][j]) continue;
                    gg.pb(g[i][j]);
                }
            }
            g[i] = gg;
        }
        
        return g;
    }
    
};

    
