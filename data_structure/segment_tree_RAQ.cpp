
template <typename T>
class SegmentTree_RAQ {
    int N = 1;
    T func(T a, T b){
        return a+b;
    }
public:
    ve<T> node;
    SegmentTree_RAQ(int n){
        while (N < n) {N *= 2;}
        node.assign(N*2-1,0);
        rep(i,n) node[i+N-1] = 0;
        per(i,N/2-1) node[i] = func(node[i*2+1],node[i*2+2]);
    }
    SegmentTree_RAQ(ve<T>& v){
        int n = si(v);
        while(N < n) {N*=2;}
        node.assign(N*2-1,0);
        rep(i,n) node[N-1+i] = v[i];
        per(i,N-1) node[i] = func(node[i*2+1],node[i*2+2]);
    }
    void update(int x, T val){
        x += N-1;
        node[x] += val;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = func(node[x*2+1],node[x*2+2]);
        }
    }
    T find(int a, int b, int l=0, int r=-1, int k=0){
        if(r < 0) r = N;
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        T vl = find(a,b,l,(l+r)/2,k*2+1);
        T vr = find(a,b,(l+r)/2,r,k*2+2);
        return func(vl,vr);
    }
};


