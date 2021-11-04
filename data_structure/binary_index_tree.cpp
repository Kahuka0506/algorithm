

class FenwickTree {
    int N;
    vl bit;
    
public:
    FenwickTree(int n_):N(n_){
        bit.assign(N+1,0LL);
        //rep(x,N) bit[x] = x&-x; //v_x = 1
        //for(int x = 1; x < N; ++x) bit[x+(x&-x)] += bit[x]; //bit[x] = v_x
    }
    
    void add(int a, ll w){
        for (int x = a; x <= N; x += x&-x) bit[x] += w;
    }
    
    ll sum(int a){
        ll ret = 0;
        for (int x = a; x > 0; x -= x&-x) ret += bit[x];
        return ret;
    }
    
};



template <typename T>
class BIT {
    ve<T> node;
    int n;
    
    T find(int m){
        T s = 0;
        while (m > 0) {
            s += node[m];
            m -= (m & (-m));
        }
        return s;
    }
    
public:
    BIT(int _n) : n(_n){
        node.assign(n+1,0);
    }
    
    T sum(int a, int b){
        T s_a = find(a);
        T s_b = find(b+1);
        return s_b - s_a;
    }
    
    
    void update(int m, T x){
        m++;
        while (m <= n) {
            node[m] += x;
            m += (m & (-m));
        }
    }
    
};

