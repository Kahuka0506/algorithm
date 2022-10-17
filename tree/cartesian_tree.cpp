
template <typename T>
class SegmentTree {
    int N;
    ve<pair<T,int>> node;
    pair<T,int> init_v = {ll(1LL<<31)-1LL,-1};
    //T init_v = 0;
    
    pair<T,int> func(pair<T,int> a, pair<T,int> b){
        if(a.fi <= b.fi) return a;
        else return b;
    }
    
public:
    
    SegmentTree(ve<T> v){
        int n = si(v);
        N = 1;
        while (n > N) N *= 2;
        node.resize(N*2-1,init_v);
        
        rep(i,n) node[i+N-1] = {v[i],i};
        per(i,N-1) node[i] = func(node[i*2+1], node[i*2+2]);
    }
    
    void update(int x, T val){
        x += N-1;
        node[x] = val;
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

template<typename T>
class CartesianTree{
private:
public:
    CartesianTree(){};
    vi par;
    void dfs(int l, int r, int p, SegmentTree<T> &st){
        auto [a,idx] = st.find(l,r);
        par[idx] = p;
        if(l < idx) dfs(l,idx,idx,st);
        if(idx+1 < r) dfs(idx+1,r,idx,st);
    }
    vi construct(const ve<T>& A){
        int N = si(A);
        SegmentTree st(A);
        par.assign(N,-1);
        dfs(0,N,-1,st);
        return par;
    }
};
 
