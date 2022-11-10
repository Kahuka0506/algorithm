# cumulative_sum
リンク : [../data_structure/cumulative_sum.cpp](../data_structure/cumulative_sum.cpp)    
最終更新 : 2022-10-21 22:50:28.155013

```cpp

template <typename T>
class CumulativeSum {
    int N;
public:
    ve<T> sumA;
    CumulativeSum(int n, const ve<T> &A):N(n){
        sumA.assign(N+1,0);
        rep(i,N) sumA[i+1] = sumA[i]+A[i];
    }
    T sum(int l, int r){return sumA[r]-sumA[l];}
};

```