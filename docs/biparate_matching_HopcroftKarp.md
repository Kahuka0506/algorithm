# biparate_matching_HopcroftKarp
リンク : [../graph/biparate_matching_HopcroftKarp.cpp](../graph/biparate_matching_HopcroftKarp.cpp)    
最終更新 : 2022-11-17 01:25:06.691825

```cpp

class HopcroftKarp {
    int L,R;
    
public:
    vvi G;
    vi match;
    HopcroftKarp(int _L, int _R):L(_L),R(_R){
        G.resize(L);
        match.assign(R,-1);
    }
    void add_edge(int a, int b){
        G[a].pb(b);
    }
    ve<bool> used,vv;
    vi level;
    void bfs(){
        level.assign(L,-1);
        queue<int> que;
        rep(i,L)if(!used[i]){
            que.push(i);
            level[i] = 0;
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : G[u]) {
                int w = match[v];
                if(w < 0 || level[w] != -1) continue;
                level[w] = level[u]+1;
                que.push(w);
            }
        }
    }
    bool dfs(int u){
        vv[u] = true;
        for (int v : G[u]) {
            int w = match[v];
            if(w < 0 || (!vv[w] && level[w]==level[u]+1 && dfs(w))){
                match[v] = u;
                used[u] = true;
                return true;
            }
        }
        return false;
    }
    int solve(){
        int res = 0;
        used.assign(L,false);
        while (1) {
            bfs();
            vv.assign(L,false);
            int f = 0;
            rep(i,L){
                if(!used[i] && dfs(i)) f++;
            }
            if(f == 0) return res;
            res += f;
        }
        return res;
    }
};
```