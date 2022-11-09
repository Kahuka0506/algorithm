
template <class T>
class FenwicTree {
    int N;
    
public:
    ve<T> node;
    FenwicTree(int _N):N(_N){
        node.assign(N+1,T(0));
    }
    void add(int p, T x){
        p++;
        for (; p <= N; p+=(-p&p)) node[p] += x;
    }
    T sum(int p){//[0,p)
        T x = 0;
        for (; p > 0; p-=(-p&p)) x += node[p];
        return x;
    }
    T sum(int a, int b){//[a,b)
        T xa = sum(a), xb = sum(b);
        return xb-xa;
    }
};

