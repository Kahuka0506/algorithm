

template <typename T>
class Dinic {
    int n;
    struct edge{int to; T cap; int rev;};
    ve<ve<edge>> G;
    vi level;
    vi iter;
    
public:
    Dinic(int n_):n(n_){
        G.resize(n);
        level.resize(n);
        iter.resize(n);
    }
    
    void add_edge(int from, int to, T cap){
        G[from].pb((edge){to, cap, si(G[to])});
        G[to].pb((edge){from, 0, si(G[from])-1});
    }
    
    void bfs(int s){
        level.assign(n,-1);
        queue<int> que;
        que.push(s);
        level[s] = 0;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (edge e : G[v]) {
                if(e.cap <= 0 || level[e.to] >= 0) continue;
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
    
    T dfs(int v, int t, T f){
        if(v == t) return f;
        for (int &i = iter[v]; i < si(G[v]); i++) {
            edge &e = G[v][i];
            if(e.cap <= 0 || level[v] >= level[e.to]) continue;
            
            T d = dfs(e.to, t, min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    
    T max_flow(int s, int t){
        T flow = 0;
        while (1) {
            bfs(s);
            if(level[t] < 0) return flow;
            iter.assign(n,0);
            T f;
            while ((f = dfs(s,t,infi)) > 0) {
                flow += f;
            }
        }
        return 0;
    }
    
};
