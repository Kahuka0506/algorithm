# range_min
リンク : [../data_structure/range_min.cpp](../data_structure/range_min.cpp)    
最終更新 : 2022-11-12 15:40:15.401740

```cpp

template <class T>
ve<T> RangeMin(const ve<T>& A, int K, int min_max=0){
    int N = si(A);
    ve<T> ans(N);//min/max A[i,i+K)
    deque<T> dque;
    rep(i,N){
        while(!dque.empty() && i-dque.front() >= K) dque.pop_front();
        while(!dque.empty() && (min_max == 0 ? (A[i] <= A[dque.back()]) : (A[i] >= A[dque.back()]))) dque.pop_back();
        dque.push_back(i);
        if(i-K+1 >= 0) ans[i-K+1] = A[dque.front()];
    }
    return ans;
}
```