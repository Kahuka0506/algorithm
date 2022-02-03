
template <typename T>
class Bellman_Ford {
    int N;
    ve<ve<pair<int,T>>> G;
    
public:
    
    void add_edge(int a, int b, T c) {G[a].pb({b,c});}
    Bellman_Ford(int N_):N(N_){G.resize(N);}
    
    ve<T> d;
    bool negative_cycle = false;
    void solve(int s = 0){
        d.assign(N,infl);
        d[s] = 0;
        int f = 1;
        negative_cycle = false;
        int loop = 0;
        
        while (f) {
            loop++;
            if(loop > N) {negative_cycle = true;break;}
            f = 0;
            rep(u,N) if(d[u] != infl){
                for (auto [v,w] : G[u]) {
                    if(chmin(d[v],d[u]+w)) f = 1;
                }
            }
        }
    }
    
    bool is_negative_cycle(){return negative_cycle;}
};



template <typename T>
class Bellman_Ford {
    int N;
    ve<ve<pair<int,T>>> G;
    
public:
    
    void add_edge(int a, int b, T c) {G[a].pb({b,c});}
    Bellman_Ford(int N_):N(N_){G.resize(N);}
    
    ve<T> d;
    ve<bool> cycle;
    bool negative_cycle = false;
    void solve(int s = 0){
        d.assign(N,infi);
        d[s] = 0;
        cycle.assign(N,0);
        int f = 1;
        negative_cycle = false;
        int loop = 0;
        
        while (f) {
            loop++;
            if(loop > 2*N) {negative_cycle = true;break;}
            f = 0;
            rep(u,N) if(d[u] != infi){
                for (auto [v,w] : G[u]) {
                    if(cycle[u]) cycle[v] = 1;
                    if(chmin(d[v],d[u]+w)) {
                        f = 1;
                        if(loop > N) cycle[u] = 1;
                    }
                }
            }
        }
    }
    void solve_all(){
        d.assign(N,0);
        cycle.assign(N,0);
        int f = 1;
        negative_cycle = false;
        int loop = 0;
        
        while (f) {
            loop++;
            if(loop > 2*N) {negative_cycle = true;break;}
            f = 0;
            rep(u,N) if(d[u] != infi){
                for (auto [v,w] : G[u]) {
                    if(cycle[u]) cycle[v] = 1;
                    if(chmin(d[v],d[u]+w)) {
                        f = 1;
                        if(loop > N) cycle[u] = 1;
                    }
                }
            }
        }
    }
    
    bool is_negative_cycle(){return negative_cycle;}
    bool is_negative_cycle(int u){return cycle[u];}
};

