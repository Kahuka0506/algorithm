
template <typename T> T extgcd(T a, T b, T& x, T& y){
    T d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else x=1,y=0;
    return d;
}

template <typename T> T mod_pow(T m, T n) {
    if(n == 0) return 1;
    T res = mod_pow(m*m%mod, n/2);
    if(n & 1) res *= m;
    return res%mod;
}

template <typename T> T mod_inv(T n) {
    T m = mod;
    T x,y;
    extgcd(n,m,x,y);
    return (m+x%m)%m;
}
