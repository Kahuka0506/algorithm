
class TwoEdgeConnectedComponents {
    int N;
    
public:
    vvi G;
    TwoEdgeConnectedComponents(int n):N(n){G.resize(N);}
    void add_edge(int a, int b){
        G[a].pb(b);
        edge[{a,b}]++;
    }
    
    vi lowlink, ord;
    set<pii> bridge;
    map<pii,int> edge;
    int cn;
    void dfs(int u, int u0){
        ord[u] = lowlink[u] = cn++;
        for (int v : G[u]) {
            if(v == u0) continue;
            if(ord[v] != -1){
                chmin(lowlink[u], ord[v]);
                continue;
            }
            dfs(v,u);
            chmin(lowlink[u],lowlink[v]);
            if(ord[u] < lowlink[v] && edge[{u,v}] == 1) bridge.insert({u,v});
        }
    }
    vvi res;
    vi com;
    void dfs1(int u,int c){
        com[u] = c;
        res[c].pb(u);
        for (int v : G[u]) {
            if(com[v] != -1) continue;
            if(bridge.count({u,v})){
                res.pb({});
                dfs1(v,si(res)-1);
            }else{
                dfs1(v,c);
            }
        }
    }
    vvi construct(){
        lowlink.assign(N,infi);
        ord.assign(N,-1);
        cn = 0;
        rep(i,N) if(ord[i] == -1) dfs(i,-1);
        
        res.clear();
        com.assign(N,-1);
        rep(i,N) if(com[i] == -1){
            res.pb({});
            dfs1(i,si(res)-1);
        }
        return res;
    }
    
};
