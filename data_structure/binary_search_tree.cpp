
template <class T>
class BinarySearchTree {
    function<bool(T,T)> op;
    struct node{
        T val;
        node *lch, *rch;
    };
    node *insert(node *p, T x){
        if(p == NULL) {
            node *q = new node;
            q->val = x;
            q->lch = q->rch = NULL;
            return q;
        }
        if(p->val == x) return p;
        else if(op(x,p->val)) p->lch = insert(p->lch,x);
        else p->rch = insert(p->rch,x);
        return p;
    }
    bool find(node *p, T x){
        if(p == NULL) return false;
        else if(x == p->val) return true;
        else if(op(x,p->val)) return find(p->lch,x);
        else return find(p->rch,x);
    }
    node *erase(node *p, T x){
        if(p == NULL) return NULL;
        else if(p->val == x){
            if(p->lch == NULL && p->rch == NULL){
                delete p;
                return NULL;
            }else if(p->rch == NULL){
                node *q = p->lch;
                delete p;
                return q;
            }else if(p->lch == NULL){
                node *q = p->rch;
                delete p;
                return q;
            }else{
                if(p->rch->lch == NULL){
                    node *q = p->rch;
                    q->lch = p->lch;
                    delete p;
                    return q;
                }else{
                    node *q;
                    for(q = p->rch; q->lch->lch != NULL; q=q->lch);
                    node *r = q->lch;
                    q->lch = r->rch;
                    r->lch = p->lch;
                    r->rch = p->rch;
                    delete p;
                    return r;
                }
            }
        }else if(op(x,p->val)) p->lch = erase(p->lch,x);
        else p->rch = erase(p->rch,x);
        return p;
    }
    
public:
    node *root = NULL;
    BinarySearchTree(function<bool(T,T)> _op):op(_op){root = NULL;}
    
    void insert(T x){root = insert(root,x);}
    bool find(T x){return find(root,x);}
    void erase(T x){root = erase(root,x);}
    
    
    void inorder(node *p){
        if(p == NULL) return;
        inorder(p->lch);
        cout << " " << p->val;
        inorder(p->rch);
    }
    void preorder(node *p){
        if(p == NULL) return;
        cout << " " << p->val;
        preorder(p->lch);
        preorder(p->rch);
    }
    void print(){
        inorder(root);
        cout << endl;
        preorder(root);
        cout << endl;
    }
};
