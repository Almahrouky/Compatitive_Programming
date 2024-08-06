int query(int ql, int qr, int p, int k, int sl, int sr){
    if(ql > sr || sl > qr || tree[k] > p) return 0;
    if(sr==sl){
        // logic
    }
    
    int mid = (sl + sr)/2;
    return combine(query(ql, qr, p, k<<1, sl, mid), query(ql, qr, p, k<<1 | 1, mid + 1, sr));
}
