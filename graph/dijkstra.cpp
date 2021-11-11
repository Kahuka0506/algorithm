
template <typename T>
class Dijkstra {
    int N;
    ve<ve<pair<int,T>>> G;
    
public:
    void add_edge(int u, int v, T w){G[u].pb({v,w});}
    Dijkstra(int N_):N(N_){G.resize(N);}
    ve<T> d;
    vi from;
    void solve(int s){
        d.assign(N,-1);
        from.assign(N,-1);
        pq1<pair<T,pii>> pq;
        pq.push({0,{s,-1}});
        while (!pq.empty()) {
            auto [c,uv] = pq.top();
            auto [u,u0] = uv;
            pq.pop();
            if(d[u] != -1) continue;
            d[u] = c, from[u] = u0;
            for (auto [v,w] : G[u]) {
                if(d[v] != -1) continue;
                pq.push({w+d[u],{v,u}});
            }
        }
    }
};



template <typename T>
class Dijkstra {
    int N;
    ve<ve<pair<int,T>>> G;
    
public:
    void add_edge(int u, int v, T w){G[u].pb({v,w});}
    Dijkstra(int N_):N(N_){G.resize(N);}
    ve<T> d;
    void solve(int s){
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
};





//old
class Dijkstra {
    int N;
public:
    ve<ve<pair<int,ll>>> g;
    
    Dijkstra(int n){
        N = n;
        g.assign(N,{});
    }
    
    vl d;
    void solve(int s){
        d.assign(N,infl);
        
        pq1<pair<ll,int>> que;
        que.push({0,s});
        
        while (!que.empty()) {
            pair<ll,int> p = que.top();
            que.pop();
            
            if(d[p.se] != infl) continue;
            d[p.se] = p.fi;
            
            for (pair<int,ll> v : g[p.se]) {
                if(d[v.fi] != infl) continue;
                que.push(make_pair(p.fi + v.se, v.fi));
            }
        }
    }
    
    ll dir(int v){return d[v];}
};


