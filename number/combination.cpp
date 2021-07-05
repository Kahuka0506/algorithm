
class Combination {
    vl fac,finv,inv;
public:
    Combination(ll n) {
        n++;
        fac.resize(n);finv.resize(n);inv.resize(n);
        
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        reps(i,2,n){
            fac[i] = fac[i-1]*(ll)i%mod;
            inv[i] = (ll)mod - inv[mod%i]*(ll)(mod/i)%mod;
            finv[i] = finv[i-1]*inv[i]%mod;
        }
    }
    
    ll com(ll n, ll m){
        if(n < m) return 0;
        if(n < 0 || m < 0) return 0;
        return fac[n]*(finv[m]*finv[n-m]%mod)%mod;
    }
};


//old
/*
class Combination {
    const ll M_mod = mod;
    
    ll com_modpow(ll m, ll n) {
        if(n == 0) return 1;
        ll res = com_modpow(m*m%M_mod, n/2);
        if(n & 1) res *= m;
        return res%M_mod;
    }
    
public:
    vl fact, ifact;
    Combination(ll n):fact(n+1),ifact(n+1){
        fact[0] = 1;
        ifact[0] = 1;
        
        for (ll i = 0; i<n; i++) {
            fact[i+1] = fact[i]*(i+1) % M_mod;
            ifact[i+1] = ifact[i]*com_modpow(i+1, M_mod-2) % M_mod;
        }
    }
    ll com(ll a, ll b){
        if(a == 0 && b == 0)return 1;
        if(a < b || a < 0)return 0;
        ll tmp = ifact[a-b] * ifact[b] % M_mod;
        return tmp * fact[a] % M_mod;
    }
};
*/


