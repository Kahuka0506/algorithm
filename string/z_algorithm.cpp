
vi z_algorithm(string S) {
    int N = si(S);
    vi z(N,0);
    z[0] = N;
    
    int s = 1, cn = 0;
    while (s < N) {
        while (s+cn < N && S[cn] == S[s+cn]) cn++;
        z[s] = cn;
        
        if(cn == 0){
            s++;
            continue;
        }
        
        int k = 1;
        while (k < cn && k+z[k] < cn) {
            z[s+k] = z[k];
            k++;
        }
        s += k;
        cn -= k;
    }
    return z;
}


