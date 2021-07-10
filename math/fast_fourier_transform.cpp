template <typename T>
class FFT {
    
    void dft(ve<complex<double>>& func, int inv){
        int sz = si(func);
        if(sz == 1) return;
        
        ve<complex<double>> f0,f1;
        rep(i,sz/2){
            f0.pb(func[i*2]);
            f1.pb(func[i*2+1]);
        }
        
        dft(f0,inv);
        dft(f1,inv);
        
        complex<double> pow_zeta = 1, zeta = polar(1.0, inv*2.0*acos(-1)/sz);
        
        rep(i,sz){
            func[i] = f0[i%(sz/2)] + pow_zeta * f1[i%(sz/2)];
            pow_zeta *= zeta;
        }
        
    }
    
    
public:
    
    ve<T> multiply(ve<T> A, ve<T> B){
        
        int n = 1;
        while (n < (ll)(si(A)+si(B))) n *= 2;
        
        vector<complex<double>> ff(n), g(n,0), h(n,0);
        
        rep(i,si(A)) g[i] = (complex<double>)A[i], h[i] = (complex<double>)B[i];
        dft(g,1);
        dft(h,1);
        
        rep(i,n) ff[i] = g[i]*h[i];
        dft(ff,-1);
        
        ve<T> C(n);
        rep(i,n) C[i] = T(ff[i].real()/n+0.1);
        //rep(i,n) C[i] = T(ff[i].real()/n);
        
        return C;
    }
    
    
};
