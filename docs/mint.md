# mint
リンク : [../number/mint.cpp](../number/mint.cpp)    
最終更新 : 2021-10-26 13:35:29.468221

```cpp

class mint {
    
public:
    ll x;
    
    mint(ll x = 0):x((x%mod+mod)%mod){}
    
    mint operator-() const{
        return mint(-x);
    }
    
    mint& operator+=(const mint& a){
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }
    
    mint& operator-=(const mint& a){
        if((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    
    mint& operator*=(const mint& a){
        (x *= a.x) %= mod;
        return *this;
    }
    
    mint operator+(const mint& a) const{
        mint res(*this);
        return res += a;
    }
    
    mint operator-(const mint& a) const{
        mint res(*this);
        return res *= a;
    }
    
    mint operator*(const mint& a) const{
        mint res(*this);
        return res *= a;
    }
    
    mint pow(ll t) const {
        if(!t) return 1;
        mint a = pow(t >> 1);
        a *= a;
        if(t&1) a *= *this;
        return a;
    }
    
    mint inv() const {
        return pow(mod-2);
    }
    
    mint& operator/=(const mint& a){
        return (*this) *= a.inv();
    }
    
    mint operator/(const mint& a) const{
        mint res(*this);
        return res /= a;
    }
    
    friend ostream& operator<<(ostream& os, const mint& m){
        os << m.x;
        return os;
    }
    
};


```