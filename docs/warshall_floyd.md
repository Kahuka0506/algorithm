# warshall_floyd
リンク : [../graph/warshall_floyd.cpp](../graph/warshall_floyd.cpp)    
最終更新 : 2021-10-26 13:35:29.466940

```cpp

class Warshall_Floyd {
    int N;
    
public:
    vvl g;
    Warshall_Floyd(int n){
        N = n;
        g.assign(N,vl(N,infl));
        rep(i,N) g[i][i] = 0;
    }
    
    vvl d;
    void solve(){
        d = g;
        rep(k,N) rep(i,N) rep(j,N) if(d[i][k] != infl && d[k][j] != infl) chmin(d[i][j], d[i][k]+d[k][j]);
    }
    
    bool is_negative_cycle(){
        bool f = false;
        rep(i,N) if(d[i][i] < 0) f = true;
        return f;
    }
    
    ll dir(int a, int b){return d[a][b];}
};


```