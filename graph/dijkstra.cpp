

class Dijkstra {
    int N;
public:
    ve<ve<pair<int,ll>>> g;
    
    Dijkstra(int n){
        N = n;
        g.assign(N,{});
    }
    
    vl d;
    void solve(int s){
        d.assign(N,infl);
        
        pq1<pair<ll,int>> que;
        que.push({0,s});
        
        while (!que.empty()) {
            pair<ll,int> p = que.top();
            que.pop();
            
            if(d[p.se] != infl) continue;
            d[p.se] = p.fi;
            
            for (pair<int,ll> v : g[p.se]) {
                if(d[v.fi] != infl) continue;
                que.push(make_pair(p.fi + v.se, v.fi));
            }
        }
    }
    
    ll dir(int v){return d[v];}
};





