# min_cost_flow_negative_cycle
リンク : [../graph/min_cost_flow_negative_cycle.cpp](../graph/min_cost_flow_negative_cycle.cpp)    
最終更新 : 2021-10-26 13:35:29.466353

```cpp

template <typename T>
class MinCostFlow {
    struct edge{int to; T cap, cost; int rev;};
    int n;
    ve<ve<edge>> G;
    ve<T> dist;
    vi prevv,preve;
    
public:
    
    MinCostFlow(int n_):n(n_){
        G.resize(n);
        dist.resize(n);
        prevv.resize(n);
        preve.resize(n);
    }
    
    void add_edge(int from, int to, T cap, T cost){
        G[from].pb((edge){to, cap, cost, si(G[to])});
        G[to].pb((edge){from, 0, -cost, si(G[from])-1});
    }
    
    T min_cost_flow(int s, int t, T f){
        T res = 0;
        while (f > 0) {
            dist.assign(n,infi);
            dist[s] = 0;
            bool update = true;
            
            while (update) {
                update = false;
                rep(v,n){
                    if(dist[v] == infi) continue;
                    rep(i,si(G[v])){
                        edge &e = G[v][i];
                        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost){
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }
            
            if(dist[t] == infi){
                return -1;
            }
            
            T d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d*dist[t];
            for (int v = t; v != s; v = prevv[v]) {
                edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        
        return res;
        
        
    }
    
};
```