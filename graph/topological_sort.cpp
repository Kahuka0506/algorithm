
class TopologicalSort {
    int n;
    vvi g;
    
public:
    TopologicalSort(int n_):n(n_){g.resize(n);}
    void add_edge(int x, int y){g[x].pb(y);}
    
    vi ord;
    ve<bool> used;
    
    void dfs(int u){
        used[u] = true;
        for (int p : g[u]) {
            if(used[p]) continue;
            dfs(p);
        }
        ord.pb(u);
    }
    
    
    void tp_sort(){
        used.assign(n,false);
        rep(i,n) if(!used[i]){
            dfs(i);
        }
        reverse(all(ord));
    }
};
