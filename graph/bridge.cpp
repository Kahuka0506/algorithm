
class Bridge{
private:
    int N;
public:
    vvi G;
    Bridge(int n):N(n){G.resize(N);}
    Bridge(int n, const vvi &g):N(n){G = g;}
    void add_edge(int a, int b){G[a].pb(b);}

    vi ord, lowlink;
    ve<pii> bridge;
    int cn = 0;
    void dfs(int u, int u0 = -1){
        ord[u] = lowlink[u] = cn++;
        for(int v: G[u]){
            if(v == u0) continue;
            if(ord[v] != -1) {
                chmin(lowlink[u], ord[v]);
                continue;
            }
            dfs(v,u);
            chmin(lowlink[u],lowlink[v]);
            if(ord[u] < lowlink[v]) bridge.pb({u,v});
        }
    }
    ve<pii> solve(){
        ord.assign(N,-1);
        lowlink.assign(N,N+3);
        dfs(0);
        outve(ord);
        outve(lowlink);
        return bridge;
    }

};


