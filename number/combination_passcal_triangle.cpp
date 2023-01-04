
template <class T>
class PascalTriangle {
    vv<T> C;
    int N;
public:
    PascalTriangle(int _N):N(_N){
        C.assign(N+1,ve<T>(N+1,-1));
    }
    T com(T n, T m){
        if(n < m) return (T)0;
        if(n == 0 || m == 0 || n == m) return (T)1;
        if(C[n][m] > 0) return C[n][m];
        return C[n][m] = (com(n-1,m)+com(n-1,m-1))%mod;
    }
};
