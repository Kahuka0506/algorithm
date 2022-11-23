# interval_heap
リンク : [../data_structure/interval_heap.cpp](../data_structure/interval_heap.cpp)    
最終更新 : 2022-11-23 15:54:39.113352

```cpp

template <class T>
class IntervalHeap {
    
public:
    int N;
    ve<T> node;
    IntervalHeap(ve<T>& A){
        node = A;
        N = si(A);
        construct_binary_heap();
    };
    
    void construct_binary_heap(){
        per(i,N) correct_binary_heap(i);
    }
    void correct_binary_heap(int u){
        if(u%2==0) {
            if(u+1 < N && node[u] < node[u+1]) {
                swap(node[u],node[u+1]);
                if(u+1 < N) correct_binary_heap(u+1);
            }
            int v = u;
            if(u*2+2 < N && node[v] < node[u*2+2]) v = u*2+2;
            if(u*2+4 < N && node[v] < node[u*2+4]) v = u*2+4;
            if(v != u){
                swap(node[v],node[u]);
                correct_binary_heap(v);
            }
        }else if(u%2 == 1) {
            if(u-1 >= 0 && node[u-1] < node[u]) swap(node[u-1],node[u]);
            int v = u;
            if(u*2+1 < N && node[v] > node[u*2+1]) v = u*2+1;
            if(u*2+3 < N && node[v] > node[u*2+3]) v = u*2+3;
            if(u*2+1 == N && node[v] > node[u*2]) v = u*2;
            if(u*2+3 == N && node[v] > node[u*2+2]) v = u*2+2;
            if(v != u){
                swap(node[v],node[u]);
                correct_binary_heap(v);
            }
        }
    }
    void push(T x){
        node.pb(x);
        N++;
        int v = N-1;
        if(v%2 == 1){
            if(node[v-1] < node[v]) swap(node[v-1],node[v]);
            int p = v;
            while (p > 0) {
                int u = ((p/2-1)/2)*2+1;
                if(node[u] > node[p]) {
                    swap(node[u],node[p]);
                    p = u;
                }else break;
            }
            p = v-1;
            while (p > 0) {
                int u = ((p/2-1)/2)*2;
                if(node[u] < node[p]) {
                    swap(node[u],node[p]);
                    p = u;
                }else break;
            }
        }else{
            int p = ((v/2-1)/2)*2+1;
            if(p < v && node[p] > node[v]){
                swap(node[v],node[p]);
                while (p > 0) {
                    int u = ((p/2-1)/2)*2+1;
                    if(node[u] > node[p]) {
                        swap(node[u],node[p]);
                        p = u;
                    }else break;
                }
            }
            p = v;
            while (p > 0) {
                int u = ((p/2-1)/2)*2;
                if(node[u] < node[p]) {
                    swap(node[u],node[p]);
                    p = u;
                }else break;
            }
        }
    }
    T get_max(){return node[0];}
    T get_min(){return (N == 1 ? node[0] : node[1]);}
    void pop_max(){
        if(N < 2){
            node.pop_back();
            N--;
        }else{
            swap(node[0],node.back());
            node.pop_back();
            N--;
            correct_binary_heap(0);
        }
    }
    void pop_min(){
        if(N < 3){
            node.pop_back();
            N--;
        }else{
            swap(node[1],node.back());
            node.pop_back();
            N--;
            correct_binary_heap(1);
        }
    }
};

```