# persistent_queue
リンク : [../data_structure/persistent_queue.cpp](../data_structure/persistent_queue.cpp)    
最終更新 : 2022-10-29 00:50:53.857279

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
            backup.pb(new node);
            backup.back() = top_node;
        }
    }
};


template <class T>
class PersistentQueue {
    int que_size;
public:
    ve<pii> backup;
    PersistentStack<T> stL, stR;
    PersistentQueue(){
        que_size = 0;
        backup.pb({-1,-1});
    }
    bool empty(){return que_size==0;}
    int size(){return que_size;}
    void check(int nn = 0){
        if(stL.size() == 0){
            if(stR.size() <= nn) return;
            while (!stR.empty()) {
                stL.push(stR.top());
                stR.pop();
            }
        }
    }
    void push(T x){
        stR.push(x);
        que_size++;
        check(10);
        backup.pb({stL.backup.size()-1,stR.backup.size()-1});
    }
    void pop(){
        check();
        stL.pop();
        que_size--;
        check();
        backup.pb({stL.backup.size()-1,stR.backup.size()-1});
    }
    T front(){
        check();
        backup.pb({stL.backup.size()-1,stR.backup.size()-1});
        if(stL.size() == 0) return -1;
        return stL.top();
    }
    void back_to(int t){
        auto [l,r] = backup[t];
        stL.back_to(l);
        stR.back_to(r);
        que_size = stR.size()+stL.size();
        backup.pb({stL.backup.size()-1,stR.backup.size()-1});
    }
};

```