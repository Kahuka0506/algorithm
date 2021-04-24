
template <typename T>
class SegmentTree {
    int n;
    
public:
    
    vector<T> node;
    
    SegmentTree(vector<T> v){
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




