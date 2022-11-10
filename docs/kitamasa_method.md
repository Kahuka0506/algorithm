# kitamasa_method
リンク : [../math/kitamasa_method.cpp](../math/kitamasa_method.cpp)    
最終更新 : 2021-10-26 13:35:29.467179

```cpp

class Kitamasa_method {
    int K;
    vl A,c;
public:
    
    Kitamasa_method(int k_, vl c_, vl a_):K(k_),A(a_),c(c_){}
    
    vl next(vl& c0){
        vl c1(K);
        c1[0] = c0[K-1]*c[0]%mod;
        rep(i,K-1) c1[i+1] = (c0[i] + c0[K-1]*c[i+1]) % mod;
        
        return c1;
    }
    
    vl doubling(vl& c0){
        vl c1(K);
        
        vvl cc(K,vl(K));
        rep(i,K) cc[0][i] = c0[i];
        rep(i,K-1) cc[i+1] = next(cc[i]);
        
        rep(i,K) {
            c1[i] = 0;
            rep(j,K) (c1[i] += cc[0][j]*cc[j][i]) %= mod;
        }
        
        return c1;
    }
    
    ll solve(int n){
        
        if(n == 0) return A[0];
        
        vl c0(K,0),c1(K,0);
        c0[1] = 1;
        
        int p = 31;
        while ((n >> --p & 1) == 0);
        while (p-- > 0) {
            c0 = doubling(c0);
            if((n >> p) & 1){
                c1 = next(c0);
                rep(j,K) c0[j] = c1[j];
            }
        }
        
        ll res = 0;
        rep(i,K) (res += c0[i]*A[i]%mod) %= mod;
        
        return res;
        
    }
    
};

```