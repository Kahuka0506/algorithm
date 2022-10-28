
template<class T>
T cross_product(pair<T,T> a, pair<T,T> b){return a.fi*b.se-a.se*b.fi;}

template<class T>
bool is_convex(const ve<pair<T,T>>& P){
    int N = si(P);
    rep(i,N){
        pll a = {P[(i+1)%N].fi-P[i].fi,P[(i+1)%N].se-P[i].se};
        pll b = {P[(i+2)%N].fi-P[(i+1)%N].fi,P[(i+2)%N].se-P[(i+1)%N].se};
        if(cross_product(a,b) < 0LL) return false;
    }
    return true;
}


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



template<class T>
void polar_sort(ve<pair<T,T>>& p, pair<T,T> p0){
   sort(all(p),[&](pair<T,T> p_a, pair<T,T> p_b){
       pair<T,T> a = {p_a.fi-p0.fi,p_a.se-p0.se};
       pair<T,T> b = {p_b.fi-p0.fi,p_b.se-p0.se};
       bool aa = (a.se < 0 || (a.se==0 && a.fi < 0));
       bool bb = (b.se < 0 || (b.se==0 && b.fi < 0));
       if((a.fi==0&&a.se==0)) return !bb;
       else if((b.fi==0&&b.se==0)) return aa;
       if(aa == bb) return a.fi*b.se - a.se*b.fi > 0;
       else return aa > bb;
   });
}
template <class T>
ve<pair<T,T>> convexHull1(ve<pair<T,T>>& P) {
   
   int N = si(P);
   pll p0 = {infl,infl};
   rep(i,N){
       if(p0.se > P[i].se) p0 = P[i];
       else if(p0.se == P[i].se){
           if(p0.fi > P[i].fi) p0 = P[i];
       }
   }
   polar_sort(P,p0);
   cout << endl;
   rep(i,N) cout << P[i].fi csp P[i].se << endl;
   cout << endl;
   
   stack<pll> st;
   st.push(P[0]);
   st.push(P[1]);
   reps(i,2,N){
       while (!st.empty()) {
           pll p2 = st.top();
           st.pop();
           pll p1 = st.top();
           st.push(p2);
           pll a = {p2.fi-p1.fi, p2.se-p1.se};
           pll b = {P[i].fi-p2.fi, P[i].se-p2.se};
           if(a.fi*b.se - b.fi*a.se >= 0){
               st.push(P[i]);
               break;
           }else st.pop();
       }
   }
   ve<pll> res;
   while (!st.empty()) {
       res.pb(st.top());
       st.pop();
   }
   reverse(all(res));
   return res;
}





template <class T>
ve<pair<T,T>> convexHull(ve<pair<T,T>>& P) {
   
   sort(all(P));
   int N = si(P);
   
   stack<pll> st;
   st.push(P[0]);
   st.push(P[1]);
   auto check_convex = [&](int i){
       while (!st.empty()) {
           pll p2 = st.top();
           st.pop();
           pll p1 = st.top();
           st.push(p2);
           pll a = {p2.fi-p1.fi, p2.se-p1.se};
           pll b = {P[i].fi-p2.fi, P[i].se-p2.se};
           if(a.fi*b.se - b.fi*a.se >= 0){
               st.push(P[i]);
               break;
           }else st.pop();
           if(st.size() == 1) {
               st.push(P[i]);
               break;
           }
       }
   };
   reps(i,2,N) check_convex(i);
   ve<pll> resD;
   while (!st.empty()) {
       resD.pb(st.top());
       st.pop();
   }
   reverse(all(resD));
   while(!st.empty()){st.pop();}
   
   st.push(P[N-1]);
   st.push(P[N-2]);
   pers(i,N-2,0) check_convex(i);
   ve<pll> resU;
   while (!st.empty()) {
       resU.pb(st.top());
       st.pop();
   }
   reverse(all(resU));
   
   reps(i,1,si(resU)-1) resD.pb(resU[i]);
   return resD;
}
