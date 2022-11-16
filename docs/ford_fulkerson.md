# ford_fulkerson
リンク : [../graph/ford_fulkerson.cpp](../graph/ford_fulkerson.cpp)    
最終更新 : 2022-11-12 19:48:26.296530

```cpp

template <class T>
class FordFulkerson {
    int N;
    struct edge{int to; T cap; int rev;};
    
public:
    vv<edge> G;
    FordFulkerson(int _N):N(_N){
        G.resize(N);
    }
    void add_edge(int from, int to, T cap){
        G[from].pb((edge){to,cap,si(G[to])});
        G[to].pb((edge){from,0,si(G[from])-1});
    }
    ve<bool> used;
    T dfs(int u, int t, T f){
        if(u == t) return f;
        used[u] = true;
        for (edge &e : G[u]) {
            if(used[e.to] || e.cap == 0) continue;
            T d = dfs(e.to, t, min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    T max_flow(int s, int t, T e=infi){
        T flow = 0;
        while (1) {
            used.assign(N,false);
            T f = dfs(s,t,e);
            if(f == 0) break;
            flow += f;
        }
        return flow;
    }
    ve<pii> min_cut(int s){
        vi vis(N,0);
        vis[0] = 1;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (edge e : G[u]) {
                if(e.cap == 0 || vis[e.to] == 1) continue;
                que.push(e.to);
                vis[e.to] = 1;
            }
        }
        ve<pii> res;
        rep(i,N) if(vis[i]){
            for (edge e : G[i]) {
                if(vis[e.to] == 0) res.pb({i,e.to});
            }
        }
        return res;
     }
};
```