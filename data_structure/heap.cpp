
template <class T>
class Heap {
    int siz;
    function<bool(T,T)> op;
public:
    ve<T> node;
    Heap(ve<T>& A,function<bool(T,T)> _op=[](T a, T b)->bool{return a < b;}):op(_op){
        node = A;
        siz = si(A);
    }
    Heap(function<bool(T,T)> _op=[](T a, T b)->bool{return a < b;}):op(_op){
        siz = 0;
    }
    void construct_binary_heap(){
        per(i,siz) correct_binary_heap(i);
    }
    void correct_binary_heap(int n){
        int m = n;
        if(n*2+1 < siz && op(node[n*2+1],node[m])) m = n*2+1;
        if(n*2+2 < siz && op(node[n*2+2],node[m])) m = n*2+2;
        if(m == n) return;
        swap(node[n],node[m]);
        correct_binary_heap(m);
    }
    void push(T x){
        node.pb(x);
        siz++;
        int v = siz-1;
        while (v > 0) {
            int u = (v-1)/2;
            if(op(x,node[u])){
                node[v] = node[u];
                node[u] = x;
                v = u;
            }else break;
        }
    }
    T top(){return node[0];}
    int size(){return siz;}
    void pop(){
        swap(node[0],node[siz-1]);
        siz--;
        correct_binary_heap(0);
    }
};
