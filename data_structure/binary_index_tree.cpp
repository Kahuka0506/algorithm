
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

