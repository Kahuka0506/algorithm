
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
