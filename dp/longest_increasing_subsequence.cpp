
template <class T>
class LongestIncreasingSubsequence {
    int N;
    ve<T> A;
    T e;
public:
    int lis_len = 0;
    ve<T> LIS;
    vi idx,from;
    LongestIncreasingSubsequence(const ve<T>& _A, T _e):A(_A),e(_e){
        N = si(A);
        LIS.assign(N,e);
        idx.assign(N,-1);
        rep(i,N){
            int p = lbi(LIS,A[i]);
            LIS[p] = A[i];
            idx[i] = p;
        }
        lis_len = lbi(LIS,e);
    }
    int len(){return lis_len;}
    ve<T> construct(){//LIS index
        ve<T> res;
        if(lis_len == 0) return res;
        int s = lis_len-1;
        per(i,N){
            if(idx[i] == s){
                res.pb(i);
                s--;
            }
        }
        reverse(all(res));
        return res;
    }
};
