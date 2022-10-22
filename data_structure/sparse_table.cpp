
template <class T, class OP>
class SparseTable {
    T e;
    OP op;
    ve<ve<T>> data;
public:
    SparseTable(ve<T> v = ve<T>(), T _e = T(), OP _op = OP()) : e(_e), op(_op){
        int n = si(v);
        if(n == 0) return;
        int lg = 0;
        while(int(1<<(lg+1)) <= n) {lg++;}
        lg++;
        data.resize(lg);
        data[0] = v;
        int l = 1;
        reps(s,1,lg){
            data[s].assign(n,e);
            rep(i,n-l){
                data[s][i] = op(data[s-1][i], data[s-1][i+l]);
            }
            l <<= 1;
        }
    }
    T query(int l, int r) {
        if(l == r) return e;
        int u = 0;
        while (int(1<<(u+1)) <= r-l) {u++;}
        return op(data[u][l], data[u][r-(1<<u)]);
    }
};
