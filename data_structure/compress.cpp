

vi compress1(vi &A){
    int n = si(A);
    vi val = A;
    sort(all(val));
    val.erase(unique(all(val)),val.end());
    rep(i,n) A[i] = lbi(val,A[i]);
    //outve(A);
    //outve(val);
    return val;
}


vi compress2(vi& x1, vi& x2){
    
    int n = si(x1);
    vi a;
    rep(i,n){
        a.pb(x1[i]);
        a.pb(x2[i]);
        a.pb(x1[i]+1);
        a.pb(x2[i]+1);
    }
    sort(all(a));
    a.erase(unique(all(a)),a.end());
    
    rep(i,n){
        x1[i] = lbi(a,x1[i]);
        x2[i] = lbi(a,x2[i]);
    }
    
    return a;
}

