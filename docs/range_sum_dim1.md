# range_sum_dim1
リンク : [../data_structure/range_sum_dim1.cpp](../data_structure/range_sum_dim1.cpp)    
最終更新 : 2022-11-12 14:32:33.193957

```cpp

template <class T>
class RangeSum1 {
    int N;
    
public:
    ve<T> sumA;
    RangeSum1(const ve<T>& A){
        N = si(A);
        sumA.assign(N+1,0);
        rep(i,N) sumA[i+1] = sumA[i]+A[i];
    }
    T sum(int l, int r){//sum A[l,r)
        return sumA[r]-sumA[l];
    }
};
```