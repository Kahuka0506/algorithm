
template <int char_size = 26, int base = 'a'>
class Trie {
    
    struct Node{
        vi next;
        vi terminal;
        int c;
        int cnt;
        Node(int c_):c(c_),cnt(0){
            next.assign(char_size,-1);
        }
    };
    
    ve<Node> nodes;
    
public:
    Trie(){nodes.pb(Node(0));}
    
    void insert(const string& word, int word_id){
        int node_id = 0;
        rep(i,si(word)){
            int c = int(word[i]-base);
            int &next_id = nodes[node_id].next[c];
            if(next_id == -1){
                next_id = si(nodes);
                nodes.pb({Node(c)});
            }
            nodes[node_id].cnt++;
            node_id = next_id;
        }
        nodes[node_id].cnt++;
        nodes[node_id].terminal.pb({word_id});
    }
    void insert(const string &word){
        insert(word,nodes[0].cnt);
    }
    
    bool search(const string& word, bool prefix = false){
        int node_id = 0;
        rep(i,si(word)){
            int c = int(word[i]-base);
            int next_id = nodes[node_id].next[c];
            if(next_id == -1) return false;
            node_id = next_id;
        }
        return (prefix ? true : nodes[node_id].terminal.size() > 0);
    }
    
    bool start_with(const string& prefix){
        return search(prefix, true);
    }
    
    int count() const {
        return nodes[0].cnt;
    }
    
    int size() const{
        return si(nodes);
    }
    
    void dfs(int n, string s = ""){
        if(n != 0) s += char(nodes[n].c+base);
        int sz = si(nodes[n].terminal);
        if(sz > 0){
            rep(j,sz) cout << s << endl;
        }
        
        rep(i,char_size){
            if(nodes[n].next[i] == -1) continue;
            dfs(nodes[n].next[i],s);
        }
        if(n != 0) s.pop_back();
        
    }
    void print_all(){
        dfs(0);
    }
    
};



void solve(){
    
    
    Trie A;
    rep(i,20){
        int c;
        cin >> c;
        string s;
        cin >> s;
        if(c == 1) A.insert(s);
        else if(c == 2) cout << A.search(s) << endl;
        else cout << A.start_with(s) << endl;
        //rep(j,si(A.nodes)){
        //    cout << char('a'+A.nodes[j].c) csp A.nodes[j].cnt << endl;
        //}
        
        cout << i << endl;
        A.print_all();
    }
    
    
}
