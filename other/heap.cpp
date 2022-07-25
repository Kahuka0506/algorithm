 
void maxHeapify(vi &A, int i){
    
    int l = i*2+1, r = i*2+2;
    int m = i;
    if(l < si(A) && A[i] < A[l]) m = l;
    if(r < si(A) && A[m] < A[r]) m = r;
    
    if(m != i){
        swap(A[i],A[m]);
        maxHeapify(A, m);
    }
}

void buildMaxHeap(vi &A){
    per(i,si(A)/2) maxHeapify(A,i);
}

