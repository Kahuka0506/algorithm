
template <typename T> ve<pair<T,T>> prime_factorize(T n) {
    ve<pair<T,T>> res;
    for (T i = 2; i*i <= n; i++) {
        if(n % i != 0) continue;
        T e = 0;
        while (n%i == 0) {
            e++;
            n /= i;
        }
        res.pb(make_pair(i,e));
    }
    
    if(n != 1) res.pb(make_pair(n, 1));
    return res;
}


template<typename T> bool is_Prime(T n){
    if(n == 1) return false;
    for (T i = 2; i*i <= n; i++) {
        if(n % i == 0) return false;
    }
    return true;
}
