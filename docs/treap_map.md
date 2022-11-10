# treap_map
リンク : [../data_structure/treap_map.cpp](../data_structure/treap_map.cpp)    
最終更新 : 2022-10-27 01:04:43.298728

```cpp

unsigned int xorshift() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

template <class T, class D>
class TreapMap {
    function<bool(T,T)> op;
    struct node{
        T key;
        int pri;
        D val;
        node *lch, *rch;
    };
    node *insert(node *p, T x, int pri, D y){
        if(p == NULL) {
            node *q = new node;
            q->key = x;
            q->pri = pri;
            q->val = y;
            q->lch = q->rch = NULL;
            return q;
        }
        if(p->key == x) {
            p->val = y;
            return p;
        }else if(op(x,p->key)){
            p->lch = insert(p->lch,x,pri,y);
            if(p->pri < p->lch->pri) p = rightRotate(p);
        }else{
            p->rch = insert(p->rch,x,pri,y);
            if(p->pri < p->rch->pri) p = leftRotate(p);
        }
        return p;
    }
    bool find_bool(node *p, T x){
        if(p == NULL) return false;
        else if(x == p->key) return true;
        else if(op(x,p->key)) return find_bool(p->lch,x);
        else return find_bool(p->rch,x);
    }
    node *find_node(node *p, T x){
        if(p == NULL) return NULL;
        else if(x == p->key) return p;
        else if(op(x,p->key)) return find_node(p->lch,x);
        else return find_node(p->rch,x);
    }
    node *_erase(node *p, T x){
        if(p->lch == NULL && p->rch == NULL){
            delete p;
            return NULL;
        }else if(p->lch == NULL){
            p = leftRotate(p);
        }else if(p->rch == NULL){
            p = rightRotate(p);
        }else{
            if(p->lch->pri > p->rch->pri){
                p = rightRotate(p);
            }else{
                p = leftRotate(p);
            }
        }
        return erase(p,x);
    }
    node *erase(node *p, T x){
        if(p == NULL) return NULL;
        else if(p->key == x) return _erase(p,x);
        else if(op(x,p->key)) p->lch = erase(p->lch,x);
        else p->rch = erase(p->rch,x);
        return p;
    }
    node *rightRotate(node *p){
        node *q = p->lch;
        p->lch = q->rch;
        q->rch = p;
        return q;
    }
    node *leftRotate(node *p){
        node *q = p->rch;
        p->rch = q->lch;
        q->lch = p;
        return q;
    }
    node *lower_bound(node *p, T x){
        if(p == NULL) return NULL;
        else if(x < p->key) {
            node *q = lower_bound(p->lch,x);
            if(q == NULL) return p;
            else return q;
        }else if(p->key < x) {
            node *q = lower_bound(p->rch,x);
            if(q == NULL) return NULL;
            else return q;
        }else return p;
    }
    node *upper_bound(node *p, T x){
        if(x <= p->key) {
            node *q = upper_bound(p->lch,x);
            if(q == NULL) return NULL;
            else return q;
        }else if(p->key < x) {
            node *q = upper_bound(p->rch,x);
            if(q == NULL) return p;
            else return q;
        }else return p;
    }
public:
    node *root = NULL;
    TreapMap(){
        root = NULL;
        op = [](T a, T b){return a<b;};
    }
    TreapMap(function<bool(T,T)> _op):op(_op){root = NULL;}
    
    bool count(T x){return find_bool(root,x);}
    D at(T x){
        node *q = find_node(root,x);
        if(q == NULL) return 0;
        return q->val;
    }
    void insert(T x, D y){root = insert(root,x,int(xorshift()%INT_MAX),y);}
    void update(T x, D y){
        node *q = find_node(root,x);
        if(q == NULL) insert(x,y);
        else q->val = y;
    }
    void erase(T x){root = erase(root,x);}
    
    T lower_bound(T x){
        node *q = lower_bound(root,x);
        if(q == NULL) return -1;
        else return q->key;
    }
    T upper_bound(T x){
        node *q = upper_bound(root,x);
        if(q == NULL) return -1;
        else return q->key;
    }
    
};

```