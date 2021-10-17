
class UnionFind {
    int N;
public:
    vi root;
    UnionFind(int N_):N(N_){
        root.assign(N,-1);
    }
    
    int find(int a){
        if(root[a] < 0) return a;
        else return root[a] = find(root[a]);
    }
    
    void unite(int a, int b){
        int root_a = find(a), root_b = find(b);
        if(root_a == root_b) return;
        if(-root[root_a] >= -root[root_b]){
            root[root_a] += root[root_b];
            root[root_b] = root_a;
        }else{
            root[root_b] += root[root_a];
            root[root_a] = root_b;
        }
    }
    
    bool same(int a, int b){return find(a) == find(b);}
    
};

