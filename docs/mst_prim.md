# mst_prim
リンク : [../graph/mst_prim.cpp](../graph/mst_prim.cpp)    
最終更新 : 2022-10-04 00:01:05.888274

```cpp

//pq use mincost each v
template <typename T>
class Prim {
    int N;
    
public:
    ve<ve<pair<int,T>>> G;
    ve<ve<pair<int,T>>> mst;
    T mst_size = 0;
    
    Prim(int n):N(n){
        G.resize(N);
    }
    void add_edge(int a, int b, T c){
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    
    ll solve(){
        mst.assign(N,{});
        ve<T> mincost(N,infl);
        vi used(N,0);
        
        pq1<pair<T,pii>> pq;
        used[0] = 1;
        for (auto [v,c] : G[0]) {
            pq.push({c,{0,v}});
            chmin(mincost[v],c);
        }
        mst_size = 0;
        int cn = 1;
        
        while (!pq.empty()) {
            auto [c,u] = pq.top();
            pq.pop();
            if(used[u.se]) continue;
            mst_size += c;
            cn++;
            used[u.se] = 1;
            mst[u.fi].pb({u.se,c});
            mst[u.se].pb({u.fi,c});
            
            for (auto [v,w] : G[u.se]) {
                if(used[v]) continue;
                if(chmin(mincost[v],w)) pq.push({w,{u.se,v}});
            }
        }
        if(cn != N) mst_size = infl;
        return mst_size;
        
    }
};



//pq use mincost edge
template <typename T>
class PrimMethod {
    int N;
    
public:
    ve<ve<pair<int,T>>> G;
    ve<ve<pair<int,T>>> mst;
    T mst_size = 0;
    
    PrimMethod(int n):N(n){
        G.resize(N);
    }
    void add_edge(int a, int b, T c){
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    
    ll solve(){
        mst.assign(N,{});
        vi vis(N,0);
        pq1<pair<T,pii>> pq;
        for (auto [v,c] : G[0]) pq.push({c,{0,v}});
        vis[0] = 1;
        mst_size = 0;
        int cn = 1;
        
        while (!pq.empty()) {
            auto [c,u] = pq.top();
            pq.pop();
            if(vis[u.se]) continue;
            vis[u.se] = 1;
            mst_size += c;
            cn++;
            mst[u.fi].pb({u.se,c});
            mst[u.se].pb({u.fi,c});
            
            for (auto [v,w] : G[u.se]) {
                if(vis[v]) continue;
                pq.push({w,{u.se,v}});
            }
        }
        if(cn != N) mst_size = infl;
        return mst_size;
        
    }
};
 




template <typename T>
class Prim_Method {
    int N;
    
public:
    ve<ve<pair<int,T>>> g;
    Prim_Method(int n){
        N = n;
        g.assign(N,{});
    }
    
    ve<ve<pair<int,T>>> mst;
    T dis_sum = 0;
    void solve(){
        mst.assign(N,{});
        dis_sum = 0;
        
        vi f(N,0);
        f[0] = 1;
        pq1<pair<T,pii>> que;
        for (pair<int,T> p : g[0]) {
            que.push(make_pair(p.se, make_pair(0, p.fi)));
        }
        
        while (!que.empty()) {
            pair<T,pii> p = que.top();
            que.pop();
            
            if(f[p.se.se] == 1) continue;
            f[p.se.se] = 1;
            dis_sum += p.fi;
            
            mst[p.se.fi].pb(make_pair(p.se.se, p.fi));
            mst[p.se.se].pb(make_pair(p.se.fi, p.fi));
            for (pair<int,T> v : g[p.se.se]) {
                que.push(make_pair(v.se, make_pair(p.se.se, v.fi)));
            }
        }
    }
    
};
```