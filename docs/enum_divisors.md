# enum_divisors
リンク : [../number/enum_divisors.cpp](../number/enum_divisors.cpp)    
最終更新 : 2021-10-26 13:35:29.467935

```cpp

template <typename T> vector<T> enum_divisors(T n) {
    vector<T> res;
    for (T i = 1; i*i <= n; i++) {
        if(n%i == 0){
            res.push_back(i);
            if(i != n/i) res.push_back(n/i);
        }
    }
    return res;
}
```