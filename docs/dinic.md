# dinic
リンク : [../graph/dinic.cpp](../graph/dinic.cpp)    
最終更新 : 2022-11-12 19:47:16.366648

```cpp


template <class T>
class Dinic {
    int N;
    struct edge{int to; T cap; int rev;};
    
public:
    vv<edge> G;
    Dinic(int _N):N(_N){
        G.resize(N);
    }
    void add_edge(int from, int to, T cap){
        G[from].pb((edge){to,cap,si(G[to])});
        G[to].pb((edge){from,0,si(G[from])-1});
    }
    vi level,iter;
    void bfs(int s){
        level.assign(N,-1);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (edge e : G[u]) {
                if(e.cap <= 0 || level[e.to] != -1) continue;
                level[e.to] = level[u]+1;
                que.push(e.to);
            }
        }
    }
    T dfs(int u, int t, T f){
        if(u == t) return f;
        for (int &i = iter[u]; i < si(G[u]); i++) {
            edge &e = G[u][i];
            if(e.cap == 0 || level[u] >= level[e.to]) continue;
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
            bfs(s);
            if(level[t] < 0) return flow;
            iter.assign(N,0);
            T f;
            while ((f = dfs(s,t,e)) > 0) {
                flow += f;
            }
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