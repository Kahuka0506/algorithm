# tree_height
リンク : [../tree/tree_height.cpp](../tree/tree_height.cpp)    
最終更新 : 2022-10-15 00:02:32.080581

```cpp

template <typename T>
class TreeHeight {
    int N;
    ve<ve<pair<int,T>>> G;
    
public:
    TreeHeight(int n):N(n){G.resize(N);}
    void add_edge(int a, int b, T w){G[a].pb({b,w});}
    
    ve<T> pre;
    T dfs(int u, int u0){
        T res = 0;
        for (auto [v,w] : G[u]) {
            if(v == u0) continue;
            T h = dfs(v,u);
            chmax(res,h+w);
        }
        return pre[u] = res;
    }
    void dfs1(int u, int u0, T res){
        ve<T> h;
        h.pb(res);
        for (auto [v,w] : G[u]) {
            if(v == u0) continue;
            chmax(res,pre[v]+w);
            h.pb(pre[v]+w);
        }
        sort(all(h),greater<T>());
        for (auto [v,w] : G[u]) {
            if(v == u0) continue;
            if(h[0] == pre[v]+w) dfs1(v,u,h[1]+w);
            else dfs1(v,u,h[0]+w);
        }
        height[u] = res;
    }
    ve<T> height;
    ve<T> solve(){
        pre.assign(N,0);
        height.assign(N,0);
        dfs(0,-1);
        dfs1(0,-1,0);
        return height;
    }
    
};
```