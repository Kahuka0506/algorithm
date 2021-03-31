

class UnionFind {
    int N;
    
public:
    vi root;
    UnionFind(int n){
        N = n;
        root.assign(N,-1);
    }
    
    int find(int n){
        if(root[n] < 0) return n;
        else return root[n] = find(root[n]);
    }
    
    void connect(int a, int b){
        int a_root = find(a);
        int b_root = find(b);
        
        if(a_root == b_root) return;
        
        if(root[a_root] > root[b_root]){
            root[b_root] += root[a_root];
            root[a_root] = b_root;
        }else{
            root[a_root] += root[b_root];
            root[b_root] = a_root;
        }
    }
    
    bool is_same(int a, int b){
        if(find(a) == find(b)) return true;
        else return false;
    }
};

