# mo_algorithm
リンク : [../data_structure/mo_algorithm.cpp](../data_structure/mo_algorithm.cpp)    
最終更新 : 2022-11-10 01:06:11.339577

```cpp


template<class T, class OP_addL, class OP_addR, class OP_eraseL, class OP_eraseR>
class MoAlgorithm {
    int N;
    int Q;
    ve<pair<pii,int>> query;
    T e;
    OP_addL opal;
    OP_addR opar;
    OP_eraseL opel;
    OP_eraseR oper;
    
public:
    MoAlgorithm(int _N, T _e, OP_addL _opal, OP_addR _opar, OP_eraseL _opel, OP_eraseR _oper):
        N(_N), e(_e),
        opal(_opal),opar(_opar),
        opel(_opel),oper(_oper){}
    void add_query(int l, int r, int idx){query.pb({{l,r},idx});}
    
    ve<T> solve(){
        Q = si(query);
        ve<T> res(Q);
        sort(all(query));
        int sqrtQ = sqrt(N)+1;// N/max(sqrt(Q),1);
        
        int query_i = 0;
        int s = 0, t = 0;
        T val = e;
        rep(i,sqrtQ+2){
            ve<pair<pii,int>> q;
            while (query_i < Q && i*sqrtQ <= query[query_i].fi.fi && query[query_i].fi.fi <= (i+1)*sqrtQ) {
                q.pb(query[query_i]);
                query_i++;
            }
            if(si(q) == 0) continue;
            sort(all(q),[](pair<pii,int> a, pair<pii,int> b){return a.fi.se < b.fi.se;});
            
            for (auto [lr,idx] : q) {
                auto [l,r] = lr;
                while(t < r){
                    val = opar(val,t), t++;
                }
                while(l < s){
                    s--, val = opal(val,s);
                }
                while(s < l){
                    val = opel(val,s), s++;
                }
                while(r < t){
                    t--, val = oper(val,t);
                }
                res[idx] = val;
            }
        }
        return res;
    }
};
 
```