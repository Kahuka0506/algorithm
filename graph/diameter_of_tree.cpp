



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
