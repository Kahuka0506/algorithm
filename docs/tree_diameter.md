# tree_diameter
リンク : [../tree/tree_diameter.cpp](../tree/tree_diameter.cpp)    
最終更新 : 2022-10-06 23:50:17.975130

```cpp

template <typename T>
class TreeDiameter {
    int N;
    ve<ve<pair<int,T>>> G;
    ve<T> d;
    vi pa;
    int get_farhtest(int s){
        d.assign(N,-1);
        pa.assign(N,-1);
        d[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto [v,w] : G[u]) {
                if(d[v] != -1) continue;
                d[v] = d[u] + w;
                que.push(v);
                pa[v] = u;
            }
        }
        return int(max_element(all(d))-d.begin());
    }
public:
    TreeDiameter(int n):N(n){G.resize(N);}
    void add_edge(int a, int b, T c){G[a].pb({b,c});}
    int L=-1,R=-1;
    vi path;
    T solve(){
        L = get_farhtest(0);
        R = get_farhtest(L);
        int s = R;
        while (s != -1) {
            path.pb(s);
            s = pa[s];
        }
        return d[R];
    }
};




template <typename T>
class Tree_Diameter {
    int N;
    ve<ve<pair<int,T>>> G;
    void solve_dijkstra(int s, ve<T>& d){
        d.assign(N,-1);
        pq1<pair<T,int>> pq;
        pq.push({0,s});
        while (!pq.empty()) {
            auto [c,u] = pq.top();
            pq.pop();
            if(d[u] != -1) continue;
            d[u] = c;
            for (auto [v,w] : G[u]) {
                if(d[v] != -1) continue;
                pq.push({w+d[u],v});
            }
        }
    }
public:
    ve<T> ds,dt;
    int s,t;
    T diameter;
    void add_edge(int u, int v, T w) {G[u].pb({v,w});}
    Tree_Diameter(int N_):N(N_){G.resize(N);}
    void solve(int s_ = 0){
        s = s_;
        solve_dijkstra(s,ds);
        t = int(max_element(all(ds))-ds.begin());
        solve_dijkstra(t,dt);
        s = int(max_element(all(dt))-dt.begin());
        diameter = dt[s];
        solve_dijkstra(s,ds);
    }
};





template <typename T>
T diameter_of_tree(ve<ve<pair<int,T>>>& G) {
    int N = si(G);
    
    auto dfs = [&N,&G](int s, vi& d){
        d.assign(N,-1);
        d[s] = 0;
        queue<int> que;
        que.push(s);
        
        while (que.size()) {
            int q = que.front();
            que.pop();
            for (auto p : G[q]) {
                if(d[p.fi] >= 0) continue;
                que.push(p.fi);
                d[p.fi] = d[q] + p.se;
            }
        }
    };
    
    vi d(N);
    dfs(0,d);
    
    int idx = max_element(all(d))-d.begin();
    dfs(idx,d);
    
    return *max_element(all(d));
}
```