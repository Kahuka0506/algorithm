# extgcd
リンク : [../number/extgcd.cpp](../number/extgcd.cpp)    
最終更新 : 2021-10-26 13:35:29.468035

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
```