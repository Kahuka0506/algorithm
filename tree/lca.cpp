

class LCA {
    int N,M;
    vvi G;
public:
    vi d;
    vvi par;
    LCA(int n_):N(n_){
        G.resize(N);
    }
    void add_edge(int u, int v){G[u].pb(v);}
    void solve(int s = 0){
        M = 1;
        int c = 1;
        while(c*2 <= N) c*=2, M++;
        par.assign(M,vi(N,-1));
        d.assign(N,-1);
        d[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : G[u]) {
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                par[0][v] = u;
                que.push(v);
            }
        }
        reps(i,1,M){
            rep(j,N) if(par[i-1][j] != -1){
                par[i][j] = par[i-1][par[i-1][j]];
            }
        }
    }
    
    int find(int u, int v){
        if(d[u] < d[v]) swap(u,v);
        rep(i,M) if((d[u]-d[v]) & 1<<i) u = par[i][u];
        if(u == v) return u;
        per(i,M){
            if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }
};


template<typename T>
class LCA {
    int N,M;
    ve<ve<pair<int,T>>> G;
public:
    vi d;
    ve<T> dis;
    vvi par;
    ve<ve<T>> W;
    
    LCA(int n_):N(n_){
        G.resize(N);
    }
    void add_edge(int u, int v, T w){G[u].pb({v,w});}
    void solve(int s = 0){
        M = 0;
        while(int(1<<M) <= N) M++;
        par.assign(M,vi(N,-1)), W.assign(M,vi(N,-1));
        d.assign(N,-1), dis.assign(N,-1);
        d[s] = 0, dis[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto [v,w] : G[u]) {
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                dis[v] = dis[u] + w;
                par[0][v] = u;
                W[0][v] = w;
                que.push(v);
            }
        }
        reps(i,1,M){
            rep(j,N) {
                if(par[i-1][j] != -1){
                    par[i][j] = par[i-1][par[i-1][j]];
                    W[i][j] = max(W[i-1][j],W[i-1][par[i-1][j]]);
                }else W[i][j] = W[i-1][j];
            }
        }
    }
    
    int find(int u, int v){
        if(d[u] < d[v]) swap(u,v);
        rep(i,M) if((d[u]-d[v]) & 1<<i) u = par[i][u];
        if(u == v) return u;
        per(i,M){
            if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }
    
    T distance(int u, int v){
        int s = find(u,v);
        return dis[u]+dis[v]-2*dis[s];
    }
    T max_cost(int u, int v){
        T res = -infi;
        if(d[u] < d[v]) swap(u,v);
        rep(i,M) if((d[u]-d[v]) & 1<<i) {
            chmax(res,W[i][u]);
            u = par[i][u];
        }
        if(u == v) return res;
        per(i,M){
            if(par[i][u] != par[i][v]) {
                chmax(res,W[i][u]);
                chmax(res,W[i][v]);
                u = par[i][u], v = par[i][v];
            }
        }
        chmax(res,max(W[0][u],W[0][v]));
        return res;
    }
};



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
