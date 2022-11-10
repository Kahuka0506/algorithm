# topological_sort
リンク : [../graph/topological_sort.cpp](../graph/topological_sort.cpp)    
最終更新 : 2022-01-13 21:52:27.283359

```cpp


class TopologicalSort {
    int N;
    vvi G;
    vi deg,ord;
public:
    TopologicalSort(int N_):N(N_){
        G.resize(N);
        deg.assign(N,0);
    }
    void add_edge(int a, int b){
        G[a].pb(b);
        deg[b]++;
    }
    bool solve(){
        queue<int> que;
        rep(i,N) if(deg[i] == 0) {que.push(i);}
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            ord.pb(u);
            for(int v : G[u]){
                deg[v]--;
                if(deg[v] == 0) que.push(v);
            }
        }
        
        return (si(ord) == N);
    }
};




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
```