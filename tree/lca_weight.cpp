

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

