

template <typename T>
class MinCostFlow {
    int n;
    struct edge{int to; T cap, cost; int rev;};
    
    ve<ve<edge>> G;
    ve<T> h,dis;
    vi prevv, preve;
    
public:
    
    MinCostFlow(int n_):n(n_){
        G.resize(n);
        h.resize(n);
        dis.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }
    
    void add_edge(int from, int to, T cap, T cost){
        G[from].pb((edge){to, cap, cost, si(G[to])});
        G[to].pb((edge){from, 0, -cost, si(G[from])-1});
    }
    
    int min_cost_flow(int s, int t, int f){
        int res = 0;
        h.assign(n,0);
        
        while (f > 0) {
            pq1<pair<T,int>> que;
            dis.assign(n,infl);
            dis[s] = 0;
            que.push({0,s});
            
            while (!que.empty()) {
                auto p = que.top();
                que.pop();
                int v = p.se;
                for (edge& e : G[v]) {
                    if(e.cap > 0 && dis[e.to] > dis[v] + e.cost + h[v] - h[e.to]){
                        dis[e.to] = dis[v] + e.cost + h[v] - h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = G[e.to][e.rev].rev;
                        que.push({dis[e.to],e.to});
                    }
                }
            }
            
            if(dis[t] == infl) return -1;
            
            rep(i,n) h[i] += dis[i];
            
            int d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d,G[prevv[v]][preve[v]].cap);
            }
            
            f -= d;
            res += d*h[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        
        return res;
    }
    
    
};
