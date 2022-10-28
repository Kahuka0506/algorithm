
template<class T>
void polar_sort(ve<pair<T,T>>& p){
    sort(all(p),[](pair<T,T> a, pair<T,T>b){
        bool aa = (a.se < 0 || (a.se==0 && a.fi > 0));
        bool bb = (b.se < 0 || (b.se==0 && b.fi > 0));
        if((a.fi==0&&a.se==0)) return !bb;
        else if((b.fi==0&&b.se==0)) return aa;
        if(aa == bb) return a.fi*b.se - a.se*b.fi > 0;
        else return aa > bb;
    });
}


template<class T>
void polar_sort_atan2l(ve<pair<T,T>>& p){
    //sort(all(p),[](pair<T,T> a, pair<T,T> b){return atan2l(a.se,a.fi) < atan2l(b.se,b.fi);});
    ve<pair<ld,int>> t;
    //rep(i,N) t.pb({(atan2(y[i],x[i]) < 0 ? acos(-1)*2+atan2(y[i],x[i]) : atan2(y[i],x[i])),i});
    rep(i,si(p)) t.pb({atan2l(p[i].se,p[i].fi),i});
    sort(all(t));
    ve<pair<T,T>> p0 = p;
    rep(i,si(p)) p[i] = p0[t[i].se];
}
