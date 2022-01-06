
template <typename T>
class Dijkstra {
    int N;
    ve<ve<pair<int,T>>> G;
    
public:
    void add_edge(int u, int v, T w){G[u].pb({v,w});}
    Dijkstra(int N_):N(N_){G.resize(N);}
    ve<T> d;
    void solve(int s){
        d.assign(N,infi);
        pq1<pair<T,int>> pq;
        pq.push({0,s});
        d[s] = 0;
        while (!pq.empty()) {
            auto [c,u] = pq.top();
            pq.pop();
            if(d[u] < c) continue;
            for (auto [v,w] : G[u]) {
                if(chmin(d[v],d[u]+w)) pq.push({d[v],v});
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
    vi from;
    void solve(int s){
        d.assign(N,infi);
        from.assign(N,-1);
        pq1<pair<T,pii>> pq;
        pq.push({0,{s,-1}});
        d[s] = 0;
        while (!pq.empty()) {
            auto [c,uv] = pq.top();
            auto [u,u0] = uv;
            pq.pop();
            if(d[u] < c) continue;
            d[u] = c, from[u] = u0;
            for (auto [v,w] : G[u]) {
                if(chmin(d[v],d[u]+w)) pq.push({w+d[u],{v,u}});
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


