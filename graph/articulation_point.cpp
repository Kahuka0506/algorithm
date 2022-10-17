
class ArticulationPoint{
private:
    int N;
public:
    vvi G;
    ArticulationPoint(int n):N(n){G.resize(N);}
    ArticulationPoint(int n, const vvi &g):N(n){G = g;}
    void add_edge(int a, int b){G[a].pb(b);}

    vi ord, lowlink;
    vi articulation_point;
    int cn = 0;
    void dfs(int u, int u0 = -1){
        ord[u] = lowlink[u] = cn++;
        if(u0 == -1 && si(G[u]) > 1) articulation_point.pb(u);
        for(int v: G[u]){
            if(v == u0) continue;
            if(ord[v] != -1) {
                chmin(lowlink[u], ord[v]);
                continue;
            }
            dfs(v,u);
            chmin(lowlink[u],lowlink[v]);
            if(u0 != -1 && ord[u] <= lowlink[v]) articulation_point.pb(u);
        }
    }
    vi solve(){
        ord.assign(N,-1);
        lowlink.assign(N,N+3);
        rep(i,N) if(ord[i] == -1) dfs(i);
        return articulation_point;
    }

};

