
template <class T>
struct frac {
    T x,y;
    frac(T _x = 0, T _y = 1) : x(_x), y(_y){}
    friend bool operator<(const frac& a, const frac& b){return a.x*b.y < b.x*a.y;}
};
