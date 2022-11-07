
class MaximumIndependentSet {
    int N;
    vvi G;
    
public:
    MaximumIndependentSet(vvi g){
        G = g;
        N = si(G);
    }
    vi res;
    vi solve(){
        vi I(N);
        rep(i,N) I[i] = i;
        sort(all(I),[&](int a, int b){return si(G[a]) > si(G[b]);});
         
        auto dfs = [&](auto &&self, int ii, ll bit, ll used)->ll{
            if(ii == N) return bit;
            int u = I[ii];
            
            if(used & 1LL << u) return self(self,ii+1, bit, used);
            else {
                int deg = 0;
                for (int v : G[u]) {
                    if(!(used & 1LL << v)) deg++;
                }
                if(deg <= 1){
                    bit |= ll(1LL << u), used |= ll(1LL << u);
                    for (int v : G[u]) used |= ll(1LL<<v);
                    return self(self, ii+1, bit, used);
                }
            }
            
            used |= ll(1LL << u);
            ll res0 = self(self,ii+1,bit, used);
            for (int v : G[u]) {
                used |= ll(1LL<<v);
                if(bit & 1LL << v) return res0;
            }
            bit |= ll(1LL << u);
            ll res1 = self(self, ii+1, bit, used);
            
            if(popcntl(res0) > popcntl(res1)) return res0;
            else return res1;
        };
        
        ll ans = dfs(dfs,0,0,0);
        res.clear();
        rep(i,N) if(ans & 1LL << i) res.pb(i);
        return res;
    }
};
