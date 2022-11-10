# matrix_determinait
リンク : [../math/matrix_determinait.cpp](../math/matrix_determinait.cpp)    
最終更新 : 2022-07-26 03:30:00.389396

```cpp

ll matrix_determinait(vvl A){
    int N = si(A);
    ll res = 1;
    rep(i,N){
        if(A[i][i] == 0){
            int id = -1;
            reps(j,i+1,N) if(A[j][i] != 0) id = j;
            if(id == -1) return 0LL;
            reps(j,i,N) swap(A[i][j],A[id][j]);
            (res *= (mod-1LL)) %= mod;
        }
        
        (res *= A[i][i]) %= mod;
        
        ll a = A[i][i];
        a = mod_inv(a);
        reps(j,i,N) (A[i][j] *= a) %= mod;
        reps(j,i+1,N){
            ll b = A[j][i];
            reps(k,i,N) (A[j][k] += (mod-A[i][k]*b%mod)%mod) %= mod;
        }
    }
    return res;
}
```