class UnionFind {
    int N;
public:
    vi root;
    UnionFind(int N_):N(N_){
        root.assign(N,-1);
    }
    
    int find(int a){
        if(root[a] < 0) return a;
        else return root[a] = find(root[a]);
    }
    
    void unite(int a, int b){
        int root_a = find(a), root_b = find(b);
        if(root_a == root_b) return;
        if(-root[root_a] >= -root[root_b]){
            root[root_a] += root[root_b];
            root[root_b] = root_a;
        }else{
            root[root_b] += root[root_a];
            root[root_a] = root_b;
        }
    }
    
    bool same(int a, int b){return find(a) == find(b);}
    
    int size(int a) {return -root[find(a)];}
};


template <typename T>
class Kruskal {
    int N;
    
public:
    ve<pair<pii,T>> edges;
    ve<ve<pair<int,T>>> mst;
    T mst_size = 0;
    
    
    Kruskal(int n):N(n){}
    void add_edge(int a, int b, T c){
        edges.pb({{a,b},c});
    }
    
    T solve(){
        mst.assign(N,{});
        UnionFind U(N);
        mst_size = 0;
        
        sort(all(edges),[](pair<pii,T> a, pair<pii,T> b){return a.se < b.se;});
        rep(i,si(edges)){
            auto [uv,w] = edges[i];
            auto [u,v] = uv;
            if(U.same(u,v)) continue;
            U.unite(u,v);
            mst_size += w;
            
            mst[u].pb({v,w});
            mst[v].pb({u,w});
        }
        if(U.size(0) != N) mst_size = infl;
        return mst_size;
    }
};
