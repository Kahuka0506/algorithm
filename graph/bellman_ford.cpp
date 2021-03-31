

struct edge { int from, to, cost; };
struct bellman_ford {
    vector<edge> es;
    vector<int> d;
    int V;
    int loop = 0;
    bool negative_cycle = false;
    bellman_ford(int v){
        d.assign(v,infi);
        V = v;
    }
    
    void solve_d(int s){
        rep(i,V) d[i] = infi;
        d[s] = 0;
        while (true) {
            loop++;
            if(loop > V){
                negative_cycle = true;
                break;
            }
            bool update = false;
            for(edge e : es){
                if(d[e.from] != infi && d[e.to] > d[e.from] + e.cost){
                    d[e.to] = d[e.from] + e.cost;
                    update = true;
                }
            }
            if(!update) break;
            
        }
    }
    
    int dir(int a){
        return d[a];
    }
    
    bool is_negative_cycle(){
        return negative_cycle;
    }
    
};


//TODO
/*
template <typename T> class Bellman_Ford {
public:
    int N;
    ve<ve<pair<int,T>>> G;
    ve<T> d;
    
    bool negative_loop = false;
    
    Bellman_Ford(int &N_, ve<ve<pair<int,T>>> &G_) : N(N_), G(G_){}
    
    
    void solve(int v){
        d.assign(N, infi);
        d[v] = 0;
        
        bool changed = true;
        int roop = 0;
        while (changed) {
            changed = false;
            rep(i,N) {
                for (pair<int,T> p : G[i]) {
                    if(d[i] != infi && d[p.fi] > d[i] + p.se){
                        d[p.fi] = d[i] + p.se;
                        changed = true;
                    }
                }
            }
            
            if(changed) roop++;
            if(roop > N){
                negative_loop = true;
                break;
            }
        }
    }
    
    T dis(int v){
        return d[v];
    }
    
    bool is_negative_loop(){
        return negative_loop;
    }
};

*/
