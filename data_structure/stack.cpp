
template <class T>
class Stack {
    struct node{
        T val;
        node *par;
    };
    node *root,*top_node;
    int stack_size;
public:
    Stack(){
        root = NULL;
        top_node = root;
        stack_size = 0;
    }
    int size(){return stack_size;}
    bool empty(){return stack_size == 0;}
    void push(T x){
        node *q = new node;
        q->val = x;
        q->par = top_node;
        top_node = q;
        stack_size++;
    }
    void pop(){
        if(top_node == NULL) return;
        node *q = top_node->par;
        top_node = q;
        stack_size--;
    }
    T top(){
        if(top_node == NULL) return -1;
        return top_node->val;
    }
};
