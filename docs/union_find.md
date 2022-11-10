# union_find
リンク : [../data_structure/union_find.cpp](../data_structure/union_find.cpp)    
最終更新 : 2022-10-21 22:37:52.403380

```cpp

class UnionFind {
    int N;
    
public:
    vi root;
    int cn;
    UnionFind(int n):N(n){
        root.assign(N,-1);
        cn = N;
    }
    int find(int n){
        if(root[n] < 0) return n;
        return root[n] = find(root[n]);
    }
    void unite(int a, int b){
        int ra = find(a), rb = find(b);
        if(ra == rb) return;
        if(-root[ra] < -root[rb]) swap(ra,rb);
        root[ra] += root[rb];
        root[rb] = ra;
        cn--;
    }
    bool same(int a,int b){return find(a)==find(b);}
    int size(int n) {return -root[find(n)];}
};

```