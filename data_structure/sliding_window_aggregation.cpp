
template <class T, class OP>
class SlidingWindowAggregation {
    stack<pair<T,T>> st_front,st_back;
    T e;
    OP op;
public:
    SlidingWindowAggregation(T _e, OP _op):e(_e),op(_op){}
    void push(T x){
        T a = e;
        if(!st_back.empty()) a = st_back.top().se;
        st_back.push({x,op(a,x)});
    }
    void pop(){
        if(st_front.empty()){
            while (!st_back.empty()) {
                pair<T,T> y = st_back.top();
                st_back.pop();
                y.se = op(y.fi, (st_front.empty() ? e : st_front.top().se));
                st_front.push(y);
            }
        }
        st_front.pop();
    }
    T prod(){
        return op((st_front.empty()?e:st_front.top().se), (st_back.empty()?e:st_back.top().se));
    }
};
