# hld_exec
リンク : [../tree/hld_exec.cpp](../tree/hld_exec.cpp)    
最終更新 : 2022-10-28 01:18:14.707581

```cpp

class HLDExec {
    int N;
    vvi G;
public:
    int root;
    HLDExec(const vvi& _G, int _root = 0){
        G = _G, N = si(G);
        root = _root;
        construct(root);
    }
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
    
    template<class OP>
    void prod(int u, int v, OP op){
        while (head[u] != head[v]) {
            if(d[head[u]] > d[head[v]]) swap(u,v);
            op(pos[head[v]], pos[v]+1);
            v = par[head[v]];
        }
        if(d[u] > d[v]) swap(u,v);
        op(pos[u]+1,pos[v]+1);
    }
};
```