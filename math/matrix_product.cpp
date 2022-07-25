
vvl matrix_product(vvl &A, vvl &B){
    int N = si(A), M = si(B), K = si(B[0]);
    vvl C(N,vl(K,0));
    rep(i,N) rep(j,K) rep(k,M) (C[i][j] += A[i][k]*B[k][j]%mod) %= mod;
    return C;
}

