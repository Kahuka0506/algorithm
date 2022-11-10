# lazy_segment_tree_RAQ
リンク : [../data_structure/lazy_segment_tree_RAQ.cpp](../data_structure/lazy_segment_tree_RAQ.cpp)    
最終更新 : 2021-10-26 13:35:29.464648

```cpp

template <typename T>
class LazySegmentTree {
    int N;
    ve<T> node,lazy;
    //T init_v = ll(1LL<<31)-1LL;
    T init_v = 0;
    
    T func(T a, T b){
        //return min(a,b);
        return a+b;
    }
    
    T f_lazy = 0;
    
public:
    
    LazySegmentTree(ve<T> v){
        int n = si(v);
        N = 1;
        while (n > N) N *= 2;
        node.resize(N*2-1,init_v);
        lazy.assign(N*2-1,f_lazy);
        
        rep(i,n) node[i+N-1] = v[i];
        per(i,N-1) node[i] = func(node[i*2+1], node[i*2+2]);
    }
    
    void eval(int k, int l, int r){
        if(lazy[k] == f_lazy) return;
        
        node[k] += lazy[k];
        if(r-l > 1){
            lazy[2*k+1] += lazy[k]/2;
            lazy[2*k+2] += lazy[k]/2;
        }
        lazy[k] = f_lazy;
        
    }
    
    
    void update(int a, int b, T val, int k=0, int l=0, int r=-1){
        if(r < 0) r = N;
        eval(k,l,r);
        
        if(b <= l || r <= a) return;
        
        if(a <= l && r <= b) {
            lazy[k] += (ll)(r-l)*val;
            eval(k,l,r);
        }else{
            update(a,b,val,2*k+1,l,(l+r)/2);
            update(a,b,val,2*k+2,(l+r)/2,r);
            node[k] = func(node[2*k+1], node[2*k+2]);
        }
    }
    
    
    
    T find(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = N;
        if(r <= a || b <= l) return init_v;
        
        eval(k,l,r);
        
        if(a <= l && r <= b) return node[k];
        T vl = find(a,b,2*k+1,l,(l+r)/2);
        T vr = find(a,b,2*k+2,(l+r)/2,r);
        
        return func(vl,vr);
    }
};
```