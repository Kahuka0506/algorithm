# treap
リンク : [../data_structure/treap.cpp](../data_structure/treap.cpp)    
最終更新 : 2022-10-27 01:04:05.900402

```cpp

unsigned int xorshift() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

template <class T>
class Treap {
    function<bool(T,T)> op;
    struct node{
        T val;
        int pri;
        node *lch, *rch;
    };
    node *insert(node *p, T x, int pri){
        if(p == NULL) {
            node *q = new node;
            q->val = x;
            q->pri = pri;
            q->lch = q->rch = NULL;
            return q;
        }
        if(p->val == x) return p;
        else if(op(x,p->val)){
            p->lch = insert(p->lch,x,pri);
            if(p->pri < p->lch->pri) p = rightRotate(p);
        }else {
            p->rch = insert(p->rch,x,pri);
            if(p->pri < p->rch->pri) p = leftRotate(p);
        }
        return p;
    }
    bool find(node *p, T x){
        if(p == NULL) return false;
        else if(x == p->val) return true;
        else if(op(x,p->val)) return find(p->lch,x);
        else return find(p->rch,x);
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
        else if(p->val == x) return _erase(p,x);
        else if(op(x,p->val)) p->lch = erase(p->lch,x);
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
        else if(x < p->val) {
            node *q = lower_bound(p->lch,x);
            if(q == NULL) return p;
            else return q;
        }else if(p->val < x) {
            node *q = lower_bound(p->rch,x);
            if(q == NULL) return NULL;
            else return q;
        }else return p;
    }
    node *upper_bound(node *p, T x){
        if(x <= p->val) {
            node *q = upper_bound(p->lch,x);
            if(q == NULL) return NULL;
            else return q;
        }else if(p->val < x) {
            node *q = upper_bound(p->rch,x);
            if(q == NULL) return p;
            else return q;
        }else return p;
    }
public:
    node *root = NULL;
    Treap(){
        root = NULL;
        op = [](T a, T b){return a<b;};
    }
    Treap(function<bool(T,T)> _op):op(_op){root = NULL;}
    
    void insert(T x){root = insert(root,x,int(xorshift()%INT_MAX));}
    bool find(T x){return find(root,x);}
    void erase(T x){root = erase(root,x);}
    T lower_bound(T x){
        node *q;
        q = lower_bound(root,x);
        if(q == NULL) return -1;
        else return q->val;
    }
    T upper_bound(T x){
        node *q;
        q = upper_bound(root,x);
        if(q == NULL) return -1;
        else return q->val;
    }
    
};

```