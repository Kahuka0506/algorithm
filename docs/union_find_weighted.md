# union_find_weighted
リンク : [../data_structure/union_find_weighted.cpp](../data_structure/union_find_weighted.cpp)    
最終更新 : 2022-10-21 22:38:08.465296

```cpp

class WeightedUnionFind {
    int N;
    vi root;
    vi w;
    
public:
    WeightedUnionFind(int N_):N(N_){
        root.assign(N,-1);
        w.assign(N,0);
    }
    
    int find(int a){
        if(root[a] < 0) return a;
        else {
            int r = find(root[a]);
            w[a] += w[root[a]];
            return root[a] = r;
        }
    }
    
    int weight(int a){
        find(a);
        return w[a];
    }
    
    void unite(int a, int b, int c){
        c += (weight(a)-weight(b));
        a = find(a), b = find(b);
        if(a == b) return;
        
        if(-root[a] < -root[b]){
            c = -c;
            root[b] += root[a];
            root[a] = b;
            w[a] = c;
        }else{
            root[a] += root[b];
            root[b] = a;
            w[b] = c;
        }
    }
    
    bool same(int a, int b){return find(a) == find(b);}
    
    int diff(int a, int b){return weight(b)-weight(a);}
};

```