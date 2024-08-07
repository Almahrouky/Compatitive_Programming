struct seg{
    seg(){

    }
    seg(int u){
        
    }
};
struct segTree{
    vector<seg>tree;
    int n;

    seg combine(seg left, seg right){
        seg ret;
        
        return ret;
    }

    void build(int nn, int *arr){
        if(__builtin_popcount(nn) != 1)
            n = 1<<(__lg(nn) + 1);
        else
            n = nn;

        tree.resize(n<<1);
        for(int i = 0; i < nn; ++i)
            tree[i + n] = seg(arr[i]);
        for(int i = nn; i < n; ++i)
            tree[i] = seg();
        for(int i = n - 1; i ; --i)
            tree[i] = combine(tree[i<<1], tree[i<<1 | 1]);
    }

    seg query(int ql, int qr, int k, int sl, int sr){
        if(ql <= sl && sr <= qr)
            return tree[k];
        if(ql > sr || sl > qr)
            return seg();
        
        int mid = (sl + sr)/2;
        return combine(query(ql, qr, k<<1, sl, mid), query(ql, qr, k<<1 | 1, mid + 1, sr));
    }

    // point update
    void update(int ql, int qr, int v, int k, int sl, int sr){
        // if the segment is totaly inside the update range
        // ql == qr -> sl == sr
        if(ql <= sl && sr <= qr){
            tree[k] = seg(v);
            return ;
        }
        if(ql > sr || sl > qr)
            return ;
        
        int mid = (sl + sr)/2;
        update(ql, qr, v, k<<1, sl, mid);
        update(ql, qr, v, k<<1 | 1, mid + 1, sr);
        tree[k] = combine(tree[k<<1], tree[k<<1 | 1]);
    }
    int binWalk(int v, int k, int sl, int sr){
        if(sl == sr) // leaf
            if()  // because if initial size is 1
                return ;
            else
                return ;
 
        int mid = (sl + sr)/2;
        if(tree[k<<1] >= v)
            return binWalk(v, k<<1,sl, mid);
        else
            return binWalk(v - tree[k<<1], k<<1 | 1, mid + 1, sr);
    }
};