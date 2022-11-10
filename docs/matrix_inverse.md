# matrix_inverse
リンク : [../math/matrix_inverse.cpp](../math/matrix_inverse.cpp)    
最終更新 : 2022-07-28 07:43:09.903541

```cpp

vvl inverse_matrix(vvl A){
    
    int N = si(A);
    vvl A_inv(N,vl(N,0));
    rep(i,N) A_inv[i][i] = 1;
    
    rep(i,N){
        ll a = A[i][i];
        if(a == 0){
            int id = -1;
            reps(j,i+1,N) if(A[j][i] != 0){
                id = j;
                break;
            }
            if(id == -1) return {{-1}};
            
            rep(j,N) {
                swap(A[i][j],A[id][j]);
                swap(A_inv[i][j],A_inv[id][j]);
            }
            a = A[i][i];
        }
        a = mod_inv(a);
        rep(j,N) {
            (A[i][j] *= a) %= mod;
            (A_inv[i][j] *= a) %= mod;
        }
        reps(j,i+1,N){
            a = A[j][i];
            rep(k,N) {
                (A[j][k] += mod-A[i][k]*a%mod) %= mod;
                (A_inv[j][k] += mod-A_inv[i][k]*a%mod) %= mod;
            }
        }
    }
    per(i,N){
        per(j,i){
            ll a = A[j][i];
            rep(k,N){
                (A[j][k] += mod-A[i][k]*a%mod) %= mod;
                (A_inv[j][k] += mod-A_inv[i][k]*a%mod) %= mod;
            }
        }
    }
    return A_inv;
}
```