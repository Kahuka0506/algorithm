

ll lagrange_interpolation(vl x, vl y, ll T){
    ll n = x.size() - 1;
    ll res = 0;
    rep(i,n+1){
        ll an = y[i];
        rep(j,n+1){
            if(i == j) continue;
            (an *= ((ll)(T - x[j])+mod)%mod)%=mod;
            (an *= mod_inv(((ll)(x[i]-x[j])+mod)%mod))%=mod;
        }
        (res += an) %= mod;
    }
    return res;
}




vl lagranve_interpolation1(vl x, vl y){
    const ll n = x.size()-1;
    
    rep(i,n+1){
        ll t = 1;
        rep(j,n+1) if(i != j) (t *= (x[i]+mod-x[j])%mod) %= mod;
        (y[i] *= mod_inv(t)) %= mod;
    }
    
    ll cur = 0, nxt = 1;
    vvl dp(2,vl(n+2,0));
    dp[0][0] = (mod - x[0])%mod;
    dp[0][1] = 1;
    
    reps(i,1,n+1){
        rep(j,n+2){
            dp[nxt][j] = (mod - dp[cur][j]*x[i]%mod)%mod;
            if(j >= 1) (dp[nxt][j] += dp[cur][j-1]%mod) %= mod;
        }
        swap(nxt,cur);
    }
    
    vl xinv(n+1);
    rep(i,n+1) xinv[i] = mod_inv(x[i]);
    vl ret(n+1);
    
    rep(i,n+1){
        if(y[i] == 0) continue;
        
        if(x[i] == 0){
            rep(j,n+1) (ret[j] += dp[cur][j+1]*y[i]%mod) %= mod;
        }else{
            ret[0] += mod;
            ret[0] -= dp[cur][0]*xinv[i]*y[i]%mod;
            ret[0] %= mod;
            
            ll pre = (mod - dp[cur][0]*xinv[i]%mod) % mod;
            
            reps(j,1,n+1){
                ret[j] -= ((dp[cur][j] - pre + mod)%mod * xinv[i] * y[i] % mod)%mod;
                (ret[j] += mod) %= mod;
                pre = (mod - ((dp[cur][j] + mod - pre)%mod) * xinv[i] % mod) % mod;
            }
        }
    }
    
    return ret;
    
}





ll lagrange_interpolatio2(ll a, ll d, vl y, ll T){
    const ll n = y.size() - 1;
    ll ret = 0, ft = 1;
    rep(i,n+1) (ft *= (T + (mod - (a+d*(ll)i)%mod)%mod)%mod) %= mod;
    
    ll f = 1;
    reps(i,1,n+1) (f *= ((mod-(ll)i)%mod*d%mod) % mod) %= mod;
    (ret += y[0]*mod_inv(f)%mod* ft%mod * mod_inv((T+(mod-a)%mod)%mod)) %= mod;
    
    rep(i,n){
        (f *= d*(ll)(i+1LL)*mod_inv((d*((ll)i+(mod-n)%mod)%mod+mod) % mod)%mod) %= mod;
        (ret += y[i+1] * mod_inv(f) % mod * ft % mod * mod_inv((T+(mod-a)%mod+(mod-d)%mod*(ll)(i+1LL)%mod)%mod) % mod) %= mod;
    }
    
    return ret;
}

