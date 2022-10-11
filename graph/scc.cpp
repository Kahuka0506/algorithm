
class SCC {
   int N;
   
public:
   vvi G,rG,g;
   SCC(int n):N(n){
       G.resize(N);
       rG.resize(N);
   }
   void add_edge(int a, int b){
       G[a].pb(b);
       rG[b].pb(a);
   }
   
   int cn;
   vi vis,ord,cmp,deg;
   vvi node;
   void dfs(int u){
       vis[u] = 1;
       for (int v : G[u]) {
           if(vis[v]) continue;
           dfs(v);
       }
       ord.pb(u);
   }
   void rdfs(int u, int c){
       cmp[u] = c;
       node[c].pb(u);
       for (int v : rG[u]) {
           if(cmp[v] != -1) continue;
           rdfs(v,c);
       }
   }
   void solve(){
       vis.assign(N,0);
       ord.clear();
       rep(i,N) if(vis[i] == 0) dfs(i);
       cn = 0;
       cmp.assign(N,-1);
       per(i,N) if(cmp[ord[i]] == -1) {
           node.pb({});
           rdfs(ord[i],cn);
           cn++;
       }
   }
   void construct_dag(){
       g.resize(cn);
       node.resize(cn);
       rep(u,N){
           for (int v : G[u]) {
               if(cmp[u] != cmp[v]) g[cmp[u]].pb(cmp[v]);
           }
       }
       deg.assign(cn,0);
       rep(i,cn){
           sort(all(g[i]));
           g[i].erase(unique(all(g[i])),g[i].end());
           for (int j : g[i]) deg[j]++;
       }
   }
   vi tp_sort(){
       vi res;
       queue<int> que;
       rep(i,cn) if(deg[i] == 0) que.push(i);
       while (!que.empty()) {
           int u = que.front();
           que.pop();
           res.pb(u);
           for (int v : g[u]) {
               deg[v]--;
               if(deg[v] == 0) que.push(v);
           }
       }
       return res;
   }
   
   
};




class SCC {
    int N;
    
public:
    vvi G,rG;
    ve<bool> used;
    vi cmp,vis;
    int n_scc = 0;
    
    SCC(int n){
        N = n;
        G.resize(N);
        rG.resize(N);
        cmp.resize(N);
    }
    
    
    void dfs(int n){
        used[n] = 1;
        for (int v : G[n]) {
            if(!used[v]) dfs(v);
        }
        vis.pb(n);
    }
    
    void rdfs(int n, int k){
        used[n] = 1;
        cmp[n] = k;
        for (int v : rG[n]) {
            if(!used[v]) rdfs(v,k);
        }
    }
    
    
    void solve(){
        used.assign(N,0);
        vis.clear();
        rep(i,N) if(!used[i]) dfs(i);
        
        used.assign(N,0);
        int k = 0;
        per(i,si(vis)) if(!used[vis[i]]){
            rdfs(vis[i], k++);
        }
        n_scc = k;
    }
    
    
    vvi create_dag(){
        vvi g(n_scc);
        rep(i,N){
            for (int p : G[i]) {
                if(cmp[i] != cmp[p]) g[cmp[i]].pb(cmp[p]);
            }
        }
        rep(i,n_scc){
            vi gg;
            rep(j,si(g[i])){
                if(gg.empty()) gg.pb(g[i][j]);
                else{
                    if(gg.back() == g[i][j]) continue;
                    gg.pb(g[i][j]);
                }
            }
            g[i] = gg;
        }
        
        return g;
    }
    
};

    
