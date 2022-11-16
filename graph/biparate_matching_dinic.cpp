
template <class T>
class BiparateMatching {
    int L,R,N;
    struct edge{int to; T cap; int rev;};
    
public:
    vv<edge> G;
    BiparateMatching(int _L, int _R):L(_L),R(_R){
        N = L+R+2;
        G.resize(N);
        rep(i,L) add_edge(L+R,i-L,1);
        rep(i,R) add_edge(i+L,L+R+1-L,1);
    }
    void add_edge(int l, int r, T cap){
        r += L;
        G[l].pb((edge){r,cap,si(G[r])});
        G[r].pb((edge){l,0,si(G[l])-1});
    }
    vi level;
    void bfs(int s){
        level.assign(N,-1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (edge e : G[u]) {
                if(level[e.to] != -1 || e.cap <= 0) continue;
                level[e.to] = level[u] + 1;
                que.push(e.to);
            }
        }
    }
    vi iter;
    T dfs(int s, int t, T f){
        if(s == t) return f;
        for (int &i = iter[s]; i < si(G[s]); i++) {
            edge &e = G[s][i];
            if(level[s] >= level[e.to] || e.cap <= 0) continue;
            T d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    T max_matching(T e=infi){
        int s = L+R, t = L+R+1;
        T flow = 0;
        while (1) {
            bfs(s);
            if(level[t] < 0) return flow;
            iter.assign(N,0);
            T f;
            while ((f = dfs(s,t,e)) > 0) {
                flow += f;
            }
        }
        return flow;
    }
    ve<pii> max_matching_pair(){
        ve<pii> res;
        rep(i,L){
            for (edge e : G[i]) {
                if(e.to < L+R && e.cap == 0) res.pb(make_pair(i,e.to-L));
            }
        }
        return res;
    }
};
