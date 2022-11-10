
template <class T, class F, class OP, class OP_NL, class OP_LL>
class LazySegmentTree {
    int N;
    T e;
    OP op;
    F el;
    ve<F> lazy;
    ve<bool> lazy_f;
    OP_NL op_nl;
    OP_LL op_ll;
    
public:
    ve<T> node;
    LazySegmentTree(ve<T> v, T _e=T(), F _el=F(),
                    OP _op=OP(), OP_NL _op_nl=OP_NL(), OP_LL _op_ll=OP_LL())
    : e(_e), op(_op), el(_el), op_nl(_op_nl), op_ll(_op_ll){
        int n = si(v);
        N = int(1<<(bsr(n)+1));
        node.resize(2*N-1,e);
        lazy.resize(2*N-1,el);
        lazy_f.assign(2*N-1,false);
        rep(i,N) node[i+N-1] = v[i];
        per(i,N-1) node[i] = op(node[i*2+1],node[i*2+2]);
    }
    T get(int x){return prod(x,x+1);}
    void eval(int k, int l, int r){
        if(lazy_f[k]){
            node[k] = op_nl(node[k], lazy[k]);
            if(r - l > 1){
                lazy[k*2+1] = op_ll(lazy[k*2+1], lazy[k]);
                lazy[k*2+2] = op_ll(lazy[k*2+2], lazy[k]);
                lazy_f[k*2+1] = true;
                lazy_f[k*2+2] = true;
            }
            lazy[k] = el;
            lazy_f[k] = false;
        }
    }
    void apply(int a, int b, F x, int l=0, int r=-1, int k=0){
        if(r < 0) r = N;
        eval(k,l,r);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] = op_ll(lazy[k],x);
            lazy_f[k] = true;
            eval(k,l,r);
        }else{
            apply(a,b,x,l,(r+l)/2,k*2+1);
            apply(a,b,x,(r+l)/2,r,k*2+2);
            node[k] = op(node[k*2+1],node[k*2+2]);
        }
    }
    T prod(int a, int b, int l=0, int r=-1, int k=0){
        if(r < 0) r = N;
        if(b <= l || r <= a) return e;
        eval(k,l,r);
        if(a <= l && r <= b) return node[k];
        T vl = prod(a,b,l,(l+r)/2,2*k+1);
        T vr = prod(a,b,(l+r)/2,r,2*k+2);
        return op(vl,vr);
    }
};

auto op = [](pll a, pll b){return make_pair(a.fi+b.fi,a.se+b.se);};
auto op_ll = [](ll a, ll b){return b;};
auto op_nl = [](pll a, ll b){return make_pair(a.se*b,a.se);};
pll e = {0LL,0LL};
ll el = 0LL;
//LazySegmentTree lst(a,e,el,op,op_nl,op_ll);
