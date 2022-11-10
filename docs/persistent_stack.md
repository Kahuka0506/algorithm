# persistent_stack
リンク : [../data_structure/persistent_stack.cpp](../data_structure/persistent_stack.cpp)    
最終更新 : 2022-10-29 00:49:53.407907

```cpp

template <class T>
class PersistentStack {
    struct node{
        T val;
        node *par;
        int sz;
    };
    node *root,*top_node;
    int stack_size;
public:
    ve<node*> backup;
    PersistentStack(){
        root = new node;
        root->par = NULL;
        root->sz = 0;
        top_node = root;
        stack_size = 0;
        backup.pb(new node);
        backup.back() = top_node;
    }
    int size(){return top_node->sz;}
    bool empty(){return top_node->sz == 0;}
    void push(T x){
        node *q = new node;
        q->val = x;
        q->par = top_node;
        q->sz = top_node->sz + 1;
        top_node = q;
        backup.pb(new node);
        backup.back() = top_node;
    }
    void pop(){
        if(top_node->par == NULL) return;
        node *q = top_node->par;
        top_node = q;
        backup.pb(new node);
        backup.back() = top_node;
    }
    T top(){
        if(top_node->par == NULL) return -1;
        return top_node->val;
    }
    void back_to(int t){
        if(t == -1) t = 0;
        if(t < si(backup)) {
            node *y = *(backup.begin()+t);
            top_node = y;
            stack_size = top_node->sz;
            backup.pb(new node);
            backup.back() = top_node;
        }
    }
};
```