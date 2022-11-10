# digit_sum
リンク : [../number/digit_sum.cpp](../number/digit_sum.cpp)    
最終更新 : 2021-10-26 13:35:29.467784

```cpp

template <typename T> T digit_sum(T n) {
    T res = 0;
    while (n > 0) {
        res += n%10;
        n /= 10;
    }
    return res;
}
```