# deque_aggregation
リンク : [../data_structure/deque_aggregation.cpp](../data_structure/deque_aggregation.cpp)    
最終更新 : 2022-11-09 00:45:07.700337

```cpp

template <class T, class OP>
class DequeAggregation {
    stack<pair<T,T>> st_front,st_back;
    T e;
    OP op;
public:
    DequeAggregation(T _e, OP _op):e(_e),op(_op){}
    void push_back(T x){
        st_back.push({x,op((st_back.empty()?e:st_back.top().se),x)});
    }
    void push_front(T x){
        st_front.push({x,op(x,(st_front.empty()?e:st_front.top().se))});
    }
    void pop_front(){
        if(st_front.empty()){
            stack<pair<T,T>> st;
            int n = int(st_back.size());
            while (int(st_back.size()) > (n+1)/2) {
                pair<T,T> y = st_back.top();
                st_back.pop();
                st.push(y);
            }
            while (!st_back.empty()) {
                pair<T,T> y = st_back.top();
                st_back.pop();
                y.se = op(y.fi, (st_front.empty() ? e : st_front.top().se));
                st_front.push(y);
            }
            while (!st.empty()) {
                push_back(st.top().fi);
                st.pop();
            }
        }
        st_front.pop();
    }
    void pop_back(){
        if(st_back.empty()){
            stack<pair<T,T>> st;
            int n = int(st_front.size());
            while (int(st_front.size()) > (n+1)/2) {
                pair<T,T> y = st_front.top();
                st_front.pop();
                st.push(y);
            }
            while (!st_front.empty()) {
                pair<T,T> y = st_front.top();
                st_front.pop();
                y.se = op((st_back.empty() ? e : st_back.top().se),y.fi);
                st_back.push(y);
            }
            while (!st.empty()) {
                push_front(st.top().fi);
                st.pop();
            }
        }
        st_back.pop();
    }
    T prod(){
        return op((st_front.empty()?e:st_front.top().se), (st_back.empty()?e:st_back.top().se));
    }
};
```