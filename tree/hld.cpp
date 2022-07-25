

class HLD {
    int N;
    vvi G;
    vi siz,d,pa;
    
    int dfs_siz(int u, int v = -1){
        pa[u] = v;
        int res = 1;
        for (int p : G[u]) {
            if(p == v) continue;
            d[p] = d[u]+1;
            res += dfs_siz(p,u);
        }
        return siz[u] = res;
    }
    
    
    
public:
    
    vi hld,id,A;
    void dfs_hld(int u, int a, int v = -1){
        id[u] = si(hld);
        hld.pb(u);
        A[u] = a;
        
        int idx = -1,m = 0;
        for (int p : G[u]) {
            if(p == v) continue;
            if(chmax(m,siz[p])) idx = p;
        }

        if(idx == -1) return;
        dfs_hld(idx,a,u);

        for (int p : G[u]) {
            if(p == v || p == idx) continue;
            dfs_hld(p,p,u);
        }
        
    }
    
    HLD(int n_, vvi g_, int s = 0):N(n_),G(g_){
        siz.resize(N);
        d.assign(N,0);
        pa.assign(N,-1);
        
        dfs_siz(s);
        
        id.resize(N);
        A.resize(N);
        
        dfs_hld(s,s);
    }
    
    ve<pii> find(int u, int v){
        ve<pii> res;
        while (A[u] != A[v]) {
            if(d[A[u]] <= d[A[v]]){
                res.pb({id[A[v]],id[v]});
                v = pa[A[v]];
            }else{
                res.pb({id[A[u]],id[u]});
                u = pa[A[u]];
            }
        }
        
        res.pb({min(id[u],id[v]),max(id[u],id[v])});
        
        return res;
    }
};

