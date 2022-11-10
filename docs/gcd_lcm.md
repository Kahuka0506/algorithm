# gcd_lcm
リンク : [../number/gcd_lcm.cpp](../number/gcd_lcm.cpp)    
最終更新 : 2021-10-26 13:35:29.468124

```cpp

template <typename T> T gcd(T a, T b) {
    if(b == 0) return a;
    return gcd(b,a%b);
}

template <typename T> T lcm(T a, T b) {
    return a*b/gcd(a,b);
}
```