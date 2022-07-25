
class Euler_tour {
    int N;
    vvi G;
    
public:
    vi L,R;
    int cnt;
    
    void dfs(int u, int v=-1){
        L[u] = cnt;
        cnt++;
        for (int p : G[u]) {
            if(p == v) continue;
            dfs(p,u);
        }
        R[u] = cnt;
        cnt++;
    }
    
    Euler_tour(int n_, vvi g_, int s = 0):N(n_),G(g_){
        L.assign(N,0);
        R.assign(N,0);
        cnt = 0;
        dfs(s);
    }
    
    
};
