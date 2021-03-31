
class Prim_Method {
    int N;
    
public:
    ve<ve<pair<int,ll>>> g;
    Prim_Method(int n){
        N = n;
        g.assign(N,{});
    }
    
    ve<ve<pair<int,ll>>> mst;
    ll dis_sum = 0;
    void solve(){
        mst.assign(N,{});
        dis_sum = 0;
        
        vi f(N,0);
        f[0] = 1;
        pq1<pair<ll,pii>> que;
        for (pair<int,ll> p : g[0]) {
            que.push(make_pair(p.se, make_pair(0, p.fi)));
        }
        
        while (!que.empty()) {
            pair<ll,pii> p = que.top();
            que.pop();
            
            if(f[p.se.se] == 1) continue;
            f[p.se.se] = 1;
            dis_sum += p.fi;
            
            mst[p.se.fi].pb(make_pair(p.se.se, p.fi));
            mst[p.se.se].pb(make_pair(p.se.fi, p.fi));
            for (pair<int,ll> v : g[p.se.se]) {
                que.push(make_pair(v.se, make_pair(p.se.se, v.fi)));
            }
        }
    }
    
};


