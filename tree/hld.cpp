
class HLD{
private:
    int N;
public:
    vvi G;
    HLD(int n):N(n){G.resize(N);};
    void add_edge(int a, int b){G[a].pb(b);}

    vi par, d, heavy, head, pos;
    int cur_pos;

    int dfs(int u){
        int res = 1;
        int max_sz = 0;
        for(int v : G[u]){
            if(par[u] == v) continue;
            par[v] = u, d[v] = d[u] + 1;
            int v_sz = dfs(v);
            res += v_sz;
            if(chmax(max_sz,v_sz)) heavy[u] = v;
        }
        return res;
    }

    void construct_hld(int u, int h){
        head[u] = h, pos[u] = cur_pos++;
        if(heavy[u] != -1) construct_hld(heavy[u], h);
        for(int v : G[u]){
            if(par[u] == v || v == heavy[u]) continue;
            construct_hld(v,v);
        }
    }

    void solve(){
        par.assign(N,-1);
        d.assign(N,-1);
        heavy.assign(N,-1);
        head.resize(N);
        pos.resize(N);
        cur_pos = 0;
        d[0] = 0;
        dfs(0);
        construct_hld(0,0);

    }
    
    int lca_query(int u, int v){
        int res = 0;
        while(head[u] != head[v]){
            if(d[head[u]] > d[head[v]]) swap(u,v);
            v = par[head[v]];
        }
        if(d[u] > d[v]) swap(u,v);
        return u;
    }
};

 




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

