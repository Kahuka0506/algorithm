# lca_RMQ
リンク : [../tree/lca_RMQ.cpp](../tree/lca_RMQ.cpp)    
最終更新 : 2022-10-07 13:36:49.397881

```cpp


template <typename T>
class SegmentTree {
    int N;
    ve<pair<T,int>> node;
    pair<T,int> init_v = {ll(1LL<<31)-1LL,-1};
    
    pair<T,int> func(pair<T,int> a, pair<T,int> b){
        if(a.fi < b.fi) return a;
        else if(a.fi > b.fi) return b;
        else {
            if(a.se < b.se) return a;
            else return b;
        }
    }
    
public:
    SegmentTree(){}
    void init(ve<T> v){
        int n = si(v);
        N = 1;
        while (n > N) N *= 2;
        node.resize(N*2-1,init_v);
        
        rep(i,n) node[i+N-1] = {v[i],i};
        per(i,N-1) node[i] = func(node[i*2+1], node[i*2+2]);
    }
    
    void update(int x, T val){
        x += N-1;
        node[x].fi = val;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = func(node[2*x+1], node[2*x+2]);
        }
    }
    
    pair<T,int> find(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = N;
        if(r <= a || b <= l) return init_v;
        if(a <= l && r <= b) return node[k];
        
        pair<T,int> vl = find(a,b,2*k+1,l,(l+r)/2);
        pair<T,int> vr = find(a,b,2*k+2,(l+r)/2,r);
        
        return func(vl,vr);
    }
};






class LCA {
    int N;
    
public:
    vi d,id,seq;
    vvi G;
    SegmentTree<int> st;
    LCA(int n):N(n){}
    void dfs(int u, int u0=-1){
        seq.pb(u);
        id[u] = si(seq)-1;
        for (int v : G[u]) {
            if(v == u0) continue;
            d[v] = d[u]+1;
            dfs(v,u);
            seq.pb(u);
        }
    }
    void solve(int root, const vvi &g){
        G = g;
        d.assign(N,-1);
        id.assign(N,-1);
        seq.clear();
        d[root] = 0;
        dfs(root);
        vi dipth(si(seq));
        rep(i,si(seq)) dipth[i] = d[seq[i]];
        st.init(dipth);
    }
    int find(int u, int v){
        return seq[(st.find(min(id[u],id[v]),max(id[u],id[v])+1)).se];
    }
};
 
```