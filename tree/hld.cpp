
class HLD {
    int N;
    vvi G;
    int root;
    
public:
    HLD(int _N):N(_N){}
    HLD(const vvi& _G, int _root = 0){
        G = _G, N = si(G);
        root = _root;
        construct(root);
    }
    void add_edge(int a,int b){G[a].pb(b);}
    vi heavy,par,d;
    vi head,pos;
    int dfs(int u){
        int max_sz = 0;
        int res = 1;
        for (int v : G[u]) {
            if(par[u] == v) continue;
            par[v] = u, d[v] = d[u]+1;
            int v_sz = dfs(v);
            res += v_sz;
            if(chmax(max_sz,v_sz)) heavy[u] = v;
        }
        return res;
    }
    int cur_pos = 0;
    void construct_hld(int u, int h){
        head[u] = h, pos[u] = cur_pos++;
        if(heavy[u] != -1) construct_hld(heavy[u],h);
        for (int v : G[u]) {
            if(par[u] == v || heavy[u] == v) continue;
            construct_hld(v,v);
        }
    }
    void construct(int _root){
        root = _root;
        heavy.assign(N,-1);
        par.assign(N,-1);
        d.assign(N,0);
        dfs(root);
        cur_pos = 0;
        head.resize(N);
        pos.resize(N);
        construct_hld(root, root);
    }
    int lca(int u, int v){
        while (head[u] != head[v]) {
            if(d[head[u]] > d[head[v]]) swap(u,v);
            v = par[head[v]];
        }
        if(d[u] > d[v]) swap(u,v);
        return u;
    }
};
