

template <typename T>
class SegmentTree {
    int N;
    ve<T> node;
    T init_v = ll(1LL<<31)-1LL;
    //T init_v = 0;
    
    T func(T a, T b){
        return min(a,b);
        //return a+b;
    }
    
public:
    
    SegmentTree(ve<T> v){
        int n = si(v);
        N = 1;
        while (n > N) N *= 2;
        node.resize(N*2-1,init_v);
        
        rep(i,n) node[i+N-1] = v[i];
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
    
    T find(int a, int b, int k=0, int l=0, int r=-1){
        if(r < 0) r = N;
        if(r <= a || b <= l) return init_v;
        if(a <= l && r <= b) return node[k];
        
        T vl = find(a,b,2*k+1,l,(l+r)/2);
        T vr = find(a,b,2*k+2,(l+r)/2,r);
        
        return func(vl,vr);
    }
};








template <typename T>
class SegmentTree_RMQ {
    int n;
    vector<T> node;
    
public:
    SegmentTree_RMQ(vector<T> v){
        int sz = si(v);
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1,infl);
        
        rep(i,sz) node[n-1 + i] = v[i];
        for(int i = n-2; i >= 0; i--) node[i] = min(node[2*i+1],node[2*i+2]);
    }
    
    
    void update(int x, T value){
        x += (n-1);
        node[x] = value;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = min(node[2*x+1],node[2*x+2]);
        }
    }
    
    T find(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r = n;
        
        if(r <= a || b <= l) return infl;
        if(a <= l && r <= b) return node[k];
        
        T vl = find(a,b,2*k+1, l, (l+r)/2);
        T vr = find(a,b,2*k+2, (l+r)/2, r);
        
        return min(vl, vr);
        
    }
    
    
};





template <typename T>
class SegmentTree_RSQ {
    int n;
    
public:
    
    vector<T> node;
    
    SegmentTree_RSQ(vector<T> v){
        int sz = si(v);
        n = 1;
        while (n < sz) n *= 2;
        node.resize(2*n-1,0);
        
        rep(i,sz) node[n-1 + i] = v[i];
        for(int i = n-2; i >= 0; i--) node[i] = node[2*i+1]+node[2*i+2];
    }
    
    
    void update(int x, T value){
        x += (n-1);
        node[x] += value;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = node[2*x+1] + node[2*x+2];
        }
    }
    
    T find(int a, int b, int k=0, int l=0, int r=-1){
        if(r<0) r = n;
        
        if(r <= a || b <= l) return 0;
        if(a <= l && r <= b) return node[k];
        
        T vl = find(a,b,2*k+1, l, (l+r)/2);
        T vr = find(a,b,2*k+2, (l+r)/2, r);
        
        return vl + vr;
        
    }
    
    
};




