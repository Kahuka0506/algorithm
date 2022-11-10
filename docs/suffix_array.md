# suffix_array
リンク : [../string/suffix_array.cpp](../string/suffix_array.cpp)    
最終更新 : 2022-10-10 23:05:21.843213

```cpp

class SuffixArray {
    int N,K;
    
public:
    string S;
    vi rank,tmp,sa;
    vi lcp;
    SuffixArray(string s):S(s){
        N = si(S);
        tmp.assign(N+1,-1);
        rank.assign(N+1,-1);
        sa.assign(N+1,-1);
        rep(i,N+1){
            sa[i] = i;
            rank[i] = i < N ? int(S[i]) : -1;
        }
        
        auto compare_sa = [&](const int &i, const int &j){
            if(rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = (i + K <= N ? rank[i+K] : -1);
            int rj = (j + K <= N ? rank[j+K] : -1);
            return ri < rj;
        };
        
        for (K = 1; K <= N; K*=2) {
            sort(all(sa),compare_sa);
            tmp[sa[0]] = 0;
            reps(i,1,N+1) tmp[sa[i]] = tmp[sa[i-1]] + (compare_sa(sa[i-1],sa[i]) ? 1 : 0);
            rep(i,N+1) rank[i] = tmp[i];
        }
    }
    
    bool contain(const string &T){
        int s = 0, t = N;
        while (t-s > 1) {
            int m = (s+t)/2;
            if(S.compare(sa[m],T.length(),T) < 0) s = m;
            else t = m;
        }
        cout << t << endl;
        return S.compare(sa[t],T.length(),T) == 0;
    }
    
    void construct_lcp(){
        lcp.assign(N+1,-1);
        int h = 0;
        lcp[0] = 0;
        rep(i,N){
            int j = sa[rank[i]-1];
            if(h > 0) h--;
            for (; j+h<N && i+h<N; h++) {
                if(S[j+h] != S[i+h]) break;
            }
            lcp[rank[i]-1] = h;
        }
    }
};
```