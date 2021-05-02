
bool rolling_hash(string a, string b){
        
    int al = si(a), bl = si(b);
    if(al < bl) return false;
    
    const ull B = 100000007;
    ull t = 1;
    rep(i,bl) t *= B;
    
    ull ah = 0, bh = 0;
    rep(i,bl) {
        ah = ah*B + a[i];
        bh = bh*B + b[i];
    }
    
    for (int i = 0; i+bl <= al; i++) {
        if(ah == bh) return true;
        //if(ah == bh) if(a.substr(i,bl) == b) return true;
        if(i+bl < al) ah = ah * B + a[i+bl] - a[i]*t;
    }
    
    return false;
    
}
