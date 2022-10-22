
template <class T, class OP>
class SegmentTree_RMQ {
    int N=1;
    T e;
    OP op;
public:
    ve<T> node;
    SegmentTree_RMQ(const ve<T>& v, T _e = T(), OP _op = OP()) : e(_e), op(_op){
        int n = si(v);
        while (N < n) {N *= 2;}
        node.assign(N*2-1,e);
        rep(i,n) node[i+N-1] = v[i];
        per(i,N-1) node[i] = op(node[i*2+1],node[i*2+2]);
    }
    void update(int x, T val){
        x += N-1;
        node[x] = val;
        while (x > 0) {
            x = (x-1)/2;
            node[x] = op(node[x*2+1],node[x*2+2]);
        }
    }
    T query(int a, int b, int l=0, int r=-1, int k=0){
        if(r < 0) r = N;
        if(r <= a || b <= l) return e;
        if(a <= l && r <= b) return node[k];
        T vl = query(a,b,l,(l+r)/2,k*2+1);
        T vr = query(a,b,(l+r)/2,r,k*2+2);
        return op(vl,vr);
    }
};
