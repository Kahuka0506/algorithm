# queue
リンク : [../data_structure/queue.cpp](../data_structure/queue.cpp)    
最終更新 : 2022-10-29 00:50:35.113251

```cpp


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


template <class T>
class Queue {
    int que_size;
public:
    Stack<T> stL, stR;
    Queue(){
        que_size = 0;
    }
    bool empty(){return que_size==0;}
    int size(){return que_size;}
    void push(T x){
        stR.push(x);
        que_size++;
    }
    void pop(){
        if(stL.size() == 0){
            if(stR.size() == 0) return;
            while (!stR.empty()) {
                stL.push(stR.top());
                stR.pop();
            }
        }
        stL.pop();
        que_size--;
    }
    T front(){
        if(stL.size() == 0){
            if(stR.size() == 0) return -1;
            while (!stR.empty()) {
                stL.push(stR.top());
                stR.pop();
            }
        }
        return stL.top();
    }
    
};
```