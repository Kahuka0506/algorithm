
template <class T>
class KDTree {
    int N,K;
    struct kD_tree{
        kD_tree *lch, *rch;
        int location, axis;
    };
    kD_tree* root;
    
public:
    vv<T> data;
    KDTree(vv<T> _data):data(_data){
        root = NULL;
        N = si(data);
        K = si(data[0]);
        vi pointList(N);
        rep(i,N) pointList[i] = i;
        root = construct(pointList,0);
    }
    kD_tree *construct(vi& pointList, int dep=0){
        if(si(pointList) == 0) return NULL;
        int axis = dep%K;
        //sort(all(pointList),[&](int a, int b){return data[a][axis] < data[b][axis];});
        //int median = rand()%(si(pointList));
        int median = si(pointList)/2;
        kD_tree *p = new kD_tree;
        p->location = pointList[median];
        
        p->axis = axis;
        vi l_list,r_list;
        rep(i,si(pointList)){
            if(i == median) continue;
            if(data[pointList[i]][axis] < data[pointList[median]][axis]) l_list.pb(pointList[i]);
            else r_list.pb(pointList[i]);
        }
        //rep(i,si(pointList)/2) l_list.pb(pointList[i]);
        //reps(i,si(pointList)/2+1,si(pointList)) r_list.pb(pointList[i]);
        p->lch = construct(l_list, dep+1);
        p->rch = construct(r_list, dep+1);
        return p;
    }
    
    vi res;
    vi find_in_area(ve<T> a, ve<T> b){
        res.clear();
        ve<T> l = {-infi,-infi};
        ve<T> r = {infi,infi};
        find_in_area(root,a,b,l,r);
        return res;
    }
    void find_in_area(kD_tree *p, ve<T> a, ve<T> b, ve<T> l, ve<T> r){
        rep(i,K) if(b[i] <= l[i] || r[i] <= a[i]) return;
        int loc = p->location;
        int f = 1;
        rep(i,K) if(!(a[i] <= data[loc][i] && data[loc][i] < b[i])) {
            f = 0;
            break;
        }
        if(f) res.pb(p->location);
        ve<T> r1 = r, l1 = l;
        r1[p->axis] = data[p->location][p->axis];
        l1[p->axis] = data[p->location][p->axis];
        if(p->lch != NULL) find_in_area(p->lch,a,b,l,r1);
        if(p->rch != NULL) find_in_area(p->rch,a,b,l1,r);
    }
};


//2D
class KDTree {
    int N,K;
    struct kD_tree{
        kD_tree *lch, *rch;
        pair<pii,int> location;
        int axis;
    };
    kD_tree* root;
    
public:
    ve<pair<pii,int>> data;
    KDTree(ve<pii> _data){
        rep(i,si(_data)) data.pb({_data[i],i});
        root = NULL;
        N = si(data);
        K = 2;
        root = construct(0,N,0);
    }
    kD_tree *construct(int l, int r, int dep=0){
        if(!(l < r)) return NULL;
        int axis = dep%K;
        if(axis == 0) sort(data.begin()+l, data.begin()+r, [&](pair<pii,int> a, pair<pii,int> b){return a.fi.fi < b.fi.fi;});
        else sort(data.begin()+l, data.begin()+r, [&](pair<pii,int> a, pair<pii,int> b){return a.fi.se < b.fi.se;});
        
        kD_tree *p = new kD_tree;
        p->location = data[(r+l)/2];
        p->axis = axis;
        p->lch = construct(l,(l+r)/2, dep+1);
        p->rch = construct((l+r)/2+1,r, dep+1);
        return p;
    }
    
    vi res;
    vi find_in_area(pii a, pii b){
        res.clear();
        find_in_area(root,a,b);
        return res;
    }
    void find_in_area(kD_tree *p, pii a, pii b){
        pair<pii,int> loc = p->location;
        if(a.fi <= loc.fi.fi && loc.fi.fi <= b.fi && a.se <= loc.fi.se && loc.fi.se <= b.se) res.pb((p->location).se);
        if(p->axis == 0){
            if(p->lch != NULL && a.fi <= loc.fi.fi) find_in_area(p->lch,a,b);
            if(p->rch != NULL && b.fi >= loc.fi.fi) find_in_area(p->rch,a,b);
        }else{
            if(p->lch != NULL && a.se <= loc.fi.se) find_in_area(p->lch,a,b);
            if(p->rch != NULL && b.se >= loc.fi.se) find_in_area(p->rch,a,b);
        }
    }
};
