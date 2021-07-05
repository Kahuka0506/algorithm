
class Prime {
    int N;
    
public:
    vi prime_list, f;
    Prime(int n){ //1e7 0.4s
        N = n;
        f.resize(N+1);
        for (ll i = 2; i <= N; i++) {
            if(f[i]) continue;
            f[i] = i;
            prime_list.pb(i);
            for (ll j = i*i; j <= N; j += i) {
                if(!f[j]) f[j] = i;
            }
        }
    }
    
    bool is_prime(int n){return f[n] == n;}
    
    vi prime_factorize(int n){
        vi res;
        while (n > 1) {
            res.pb(f[n]);
            n /= f[n];
        }
        return res;
    }
    
    ve<pii> prime_factorize_pii(int n){
        vi p_list = prime_factorize(n);
        if(p_list.size() == 0) return {};
        ve<pii> res(1,{p_list[0],0});
        for (int p : p_list) {
            if(res.back().fi == p) res.back().se++;
            else res.pb(make_pair(p,1));
        }
        
        return res;
    }
    
    ll divisor_num(int n){
        ll res = 1;
        int a = 0;
        ll b = 0;
        while (n > 1) {
            if(a != f[n]){
                res *= (b+1);
                b = 0;
                a = f[n];
            }
            n /= f[n];
            b++;
        }
        res *= (b+1);
        return res;
    }
};


