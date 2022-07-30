
pair<vl,vvl> linear_equation(vvl A, vl b){
    
    int N = si(A), M = si(A[0]);
    
    vi a1(N,-1);
    int nz = 0;
    rep(i,N){
        ll a = -1;
        reps(j,nz,M){
            a = A[i][j];
            if(a == 0){
                int id = -1;
                reps(k,i+1,N) if(A[k][j] != 0){
                    id = k;
                    break;
                }
                if(id == -1) {
                    nz++;
                    if(nz == M) break;
                    continue;
                }
                reps(k,j,M) swap(A[i][k],A[id][k]);
                swap(b[id],b[i]);
                a = A[i][j];
            }
            nz = j;
            break;
        }
        if(nz == M) break;
        
        a1[i] = nz;
        a = mod_inv(a);
        reps(j,nz,M) (A[i][j] *= a) %= mod;
        (b[i] *= a) %= mod;
        
        reps(j,i+1,N){
            a = A[j][nz];
            reps(k,nz,M) {
                (A[j][k] += mod-A[i][k]*a%mod) %= mod;
            }
            (b[j] += mod-b[i]*a%mod) %= mod;
        }
        nz++;
        if(nz == M) break;
    }
     
    
    per(i,N) if(a1[i] == -1){
        if(b[i] != 0) return {{-1},{{}}};
    }
    
    vl x(M,0);
    per(i,N) if(a1[i] != -1){
        x[a1[i]] = b[i];
        reps(j,a1[i]+1,M) (x[a1[i]] += mod-A[i][j]*x[j]%mod) %= mod;
    }
    
    vvl base;
    vi aa(M,-1);
    rep(i,N) if(a1[i] != -1) aa[a1[i]] = i;
    per(i,M) if(aa[i] == -1){
        vl d(M,0);
        d[i] = 1;
        per(jj,i) if(aa[jj] != -1) {
            int j = aa[jj];
            ll y = 0;
            reps(k,j+1,i+1) (y += mod-A[j][k]*d[k]%mod) %= mod;
            d[a1[j]] = y;
        }
         
        base.pb(d);
    }
    
    
    return {x,base};
}
