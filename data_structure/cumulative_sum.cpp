
template <typename T>
class CumulativeSum {
    int N;
public:
    ve<T> sumA;
    CumulativeSum(int n, const ve<T> &A):N(n){
        sumA.assign(N+1,0);
        rep(i,N) sumA[i+1] = sumA[i]+A[i];
    }
    T sum(int l, int r){return sumA[r]-sumA[l];}
};

