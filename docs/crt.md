# crt
リンク : [../number/crt.cpp](../number/crt.cpp)    
最終更新 : 2021-10-26 13:35:29.467638

```cpp

template <typename T> T extgcd(T a, T b, T& x, T& y){
    T d = a;
    if(b != 0){
        d = extgcd(b,a%b,y,x);
        y-=(a/b)*x;
    }
    else x=1,y=0;
    return d;
}


pair<ll,ll> crt(ll b1, ll m1, ll b2, ll m2){
    ll p,q;
    ll d = extgcd(m1,m2,p,q);
    if((b2-b1) % d != 0) return make_pair(0,-1);
    
    ll m = m1*(m2/d);
    ll tmp = (b2-b1)/d*p%(m2/d);
    ll r = (b1+m1*tmp%m + m)%m;
    
    return make_pair(r,m);
}
```