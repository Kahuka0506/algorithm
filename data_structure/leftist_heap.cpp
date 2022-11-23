
template <class T>
class LeftistHeap {
    struct node{
        node* lch;
        node* rch;
        int s;
        T val;
        node(T _val):s(1),val(_val){}
    };
    node* root;
    int siz;
    function<bool(T,T)> op;
public:
    LeftistHeap(function<bool(T,T)> _op=[](T a, T b){return a < b;}):op(_op){
        root = NULL;
        siz = 0;
    }
    node* meld(node* a, node* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        if(!op(a->val, b->val)) swap(a,b);
        a->rch = meld(a->rch,b);
        if(a->lch==NULL || a->lch->s < a->rch->s) swap(a->lch,a->rch);
        a->s = (a->rch==NULL ? 0 : a->rch->s)+1;
        return a;
    }
    void meld(LeftistHeap b){
        siz += b.size();
        root = meld(root, b.root);
    }
    void push(T x){
        node* p = new node(x);
        root = meld(root,p);
        siz++;
    }
    void pop(){
        root = meld(root->lch, root->rch);
        siz--;
    }
    T top(){return root->val;}
    bool empty(){return (root==NULL);}
    int size(){return siz;}
};
