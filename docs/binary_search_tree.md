# binary_search_tree
リンク : [../other/binary_search_tree.cpp](../other/binary_search_tree.cpp)    
最終更新 : 2021-10-26 13:35:29.468712

```cpp

class Binary_Search_Tree {
    
    struct data {
        int pa;
        int left, right;
        int num;
    };

    ve<data> D;
    
public:
    Binary_Search_Tree(){
        
    }
    
    
    void insert(int a){
        if(D.size() == 0){
            D.pb((data){-1,-1,-1,a});
            return;
        }
        
        int id = 0;
        while (1) {
            if(a < D[id].num){
                if(D[id].left < 0){
                    D[id].left = si(D);
                    D.pb((data){id,-1,-1,a});
                    break;
                }else id = D[id].left;
                
            }else{
                if(D[id].right < 0){
                    D[id].right = si(D);
                    D.pb((data){id,-1,-1,a});
                    break;
                }else id = D[id].right;
            }
        }
        
    }
    
    
    
    
    
    pair<bool,int> dfs_find(int s, int a){
        if(D[s].num == a) return {true,s};
        if(a < D[s].num){
            if(D[s].left == -1) return {false,-1};
            else return dfs_find(D[s].left, a);
        }else{
            if(D[s].right == -1) return {false,-1};
            else return dfs_find(D[s].right, a);
        }
    }
    bool find(int a){
        return dfs_find(0,a).fi;
    }
    
    
    
    
    
    void dfs_print1(int s = 0){
        if(D[s].left != -1) dfs_print1(D[s].left);
        cout << " " << D[s].num;
        if(D[s].right != -1) dfs_print1(D[s].right);
        if(s == 0) cout << endl;
    }
    void dfs_print2(int s = 0){
        cout << " " << D[s].num ;
        if(D[s].left >= 0) dfs_print2(D[s].left);
        if(D[s].right >= 0) dfs_print2(D[s].right);
        if(s == 0) cout << endl;
    }
    void print(){
        dfs_print1();
        dfs_print2();
    }
    
    
    
    
    
    
    
    
    int next_id(int s){
        int res = s;
        if(D[s].left != -1) res = next_id(D[s].left);
        return res;
    }
    void delet(int a, int s = -1){
        if(s == -1) s = dfs_find(0,a).se;
        
        if(D[s].left == -1 && D[s].right == -1){
            if(D[s].pa == -1) D.clear();
            else{
                if(D[s].num < D[D[s].pa].num) D[D[s].pa].left = -1;
                else D[D[s].pa].right = -1;
            }
        }else if(D[s].right == -1){
            D[D[s].left].pa = D[s].pa;
            if(D[s].num < D[D[s].pa].num) D[D[s].pa].left = D[s].left;
            else D[D[s].pa].right = D[s].left;
            
        }else if(D[s].left == -1){
            D[D[s].right].pa = D[s].pa;
            if(D[s].num < D[D[s].pa].num) D[D[s].pa].left = D[s].right;
            else D[D[s].pa].right = D[s].right;
            
        }else{
            int ss = next_id(D[s].right);
            D[s].num = D[ss].num;
            delet(D[s].num, ss);
        }
    }
    
    
};
```