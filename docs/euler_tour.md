# euler_tour
リンク : [../tree/euler_tour.cpp](../tree/euler_tour.cpp)    
最終更新 : 2022-10-24 23:15:40.606533

```cpp

class EulerTour {
    int N;
public:
    vi L,R;
    EulerTour(){}
    EulerTour(int root, const vvi& G){construct(root,G);}
    void construct(int root, const vvi &G){
        N = si(G);
        L.resize(N);
        R.resize(N);
        int cn = 0;
        auto dfs = [&](auto &&self, int u, int u0)->bool{
            L[u] = cn++;
            for (int v : G[u]) {
                if(v == u0) continue;
                self(self,v,u);
            }
            R[u] = cn++;
            return true;
        };
        dfs(dfs,root,-1);
    }
};
```