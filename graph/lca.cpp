
class LCA {
    int N,K;
    
public:
    vvi G;
    vvi par;
    vi d;
    
    LCA(int n, vvi g, int s = 0):N(n),G(g){
        K = 0;
        while(int(1 << K) <= N) K++;
        par.assign(K,vi(N,-1));
        d.assign(N,-1);
        
        queue<int> que;
        que.push(s);
        d[s] = 0;
        par[0][s] = -1;
        while (que.size()) {
            int v = que.front();
            que.pop();
            for (int p : G[v]) {
                if(d[p] >= 0) continue;
                que.push(p);
                d[p] = d[v]+ 1;
                par[0][p] = v;
            }
        }
        
        rep(k,K-1){
            rep(j,N){
                if(par[k][j] < 0) par[k+1][j] = -1;
                else par[k+1][j] = par[k][par[k][j]];
            }
        }
    }
    
    int find_lca(int u, int v){
        if(d[u] < d[v]) swap(u,v);
        rep(k,K) if(d[u]-d[v] & 1 << k) u = par[k][u];
        
        if(u == v) return u;
        
        for (int k = K-1; k >= 0; k--) {
            if(par[k][u] != par[k][v]){
                u = par[k][u];
                v = par[k][v];
            }
        }
        
        return par[0][u];
        
    }
    
    
};
