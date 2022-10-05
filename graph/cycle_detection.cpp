
class CycleDetection {
    int N;
    vvi G;
    
public:
    CycleDetection(int n):N(n){G.resize(N);}
    void add_edge(int u, int v){G[u].pb(v);}
    vi vis,fin;
    stack<int> st;
    int base_point = -1;
    void dfs(int u){
        vis[u] = 1;
        st.push(u);
        for (int v : G[u]) {
            if(fin[v]) continue;
            if(vis[v] && !fin[v]){
                base_point = v;
                return;
            }
            if(!vis[v]) dfs(v);
            if(base_point != -1) return;
        }
        st.pop();
        fin[u] = 1;
    }
    vi find(){
        vis.assign(N,0);
        fin.assign(N,0);
        if(si(st) > 0){while(!st.empty()){st.pop();}}
        vi ans;
        rep(i,N) if(!vis[i]){
            dfs(i);
            if(base_point != -1){
                while (!st.empty()) {
                    int s = st.top();
                    st.pop();
                    ans.pb(s);
                    if(s == base_point) break;
                }
                reverse(all(ans));
                return ans;
            }
        }
        return ans;
    }
};

