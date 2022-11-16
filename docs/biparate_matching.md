# biparate_matching
リンク : [../graph/biparate_matching.cpp](../graph/biparate_matching.cpp)    
最終更新 : 2022-11-17 00:49:13.108961

```cpp

class BiparateMatching {
    int N;
    
public:
    vvi G;
    vi match,used;
    BiparateMatching(int _N):N(_N){
        G.resize(N);
    }
    void add_edge(int a, int b){
        G[a].pb(b);
        G[b].pb(a);
    }
    int timestamp;
    bool dfs(int u){
        used[u] = timestamp;
        for (int v : G[u]) {
            int w = match[v];
            if(w < 0 || (used[w] != timestamp && dfs(w))){
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }
    int solve(){
        int res = 0;
        timestamp = 0;
        match.assign(N,-1);
        used.assign(N,-1);
        rep(i,N) if(match[i] < 0){
            timestamp++;
            if(dfs(i)) res++;
        }
        return res;
    }
};
```