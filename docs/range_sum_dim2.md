# range_sum_dim2
リンク : [../data_structure/range_sum_dim2.cpp](../data_structure/range_sum_dim2.cpp)    
最終更新 : 2022-11-12 15:40:03.964193

```cpp


template <class T>
class RangeSum2 {
    int H,W;
    
public:
    vv<T> sumA;
    RangeSum2(const vv<T>& A){
        H = si(A), W = si(A[0]);
        sumA.assign(H+1,ve<T>(W+1,0));
        rep(i,H) rep(j,W){
            sumA[i+1][j+1] = A[i][j]+sumA[i+1][j]+sumA[i][j+1]-sumA[i][j];
        }
    }
    T sum(int h0, int w0, int h1, int w1){//sum A[{h0,w0},{h1,w1})
        return sumA[h1][w1]-sumA[h1][w0]-sumA[h0][w1]+sumA[h0][w0];
    }
};
```