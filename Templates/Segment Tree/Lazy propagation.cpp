struct segTree{
    vector<int>tree;
    vector<int>lazy;
    int n;

    int combine(int left, int right){
        return left + right;
    }

    void build(int nn, int *arr){
        if(__builtin_popcount(nn) != 1)
            n = 1<<(__lg(nn) + 1);
        else
            n = nn;

        tree.resize(n<<1);
        lazy.resize(n<<1, 0);  // 0 is the identity of the lazy propagation as here we calc sum so it is 0
        for(int i = 0; i < nn; ++i)
            tree[i + n] = arr[i];
        for(int i = nn; i < n; ++i)
            tree[i] = 0;
        for(int i = n - 1; i; --i)
            tree[i] = combine(tree[i<<1], tree[i<<1 | 1]);
    }

    void propagate(int k, int sl, int sr){
        if(lazy[k] != 0){  // 0 mean no pending updates
            tree[k] += lazy[k] * (sr - sl + 1);
            if(sl != sr){ // not leaf node
                lazy[k<<1] += lazy[k];
                lazy[k<<1 | 1] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    
    int query(int ql, int qr, int k, int sl, int sr){
        propagate(k, sl, sr);
        if(ql <= sl && sr <= qr)
            return tree[k];
        if(ql > sr || sl > qr)
            return 0;
        
        int mid = (sl + sr)/2;
        return combine(query(ql, qr, k<<1, sl, mid), query(ql, qr, k<<1 | 1, mid + 1, sr));
    }

    // Range update
    void update(int ql, int qr, int v, int k, int sl, int sr){
        propagate(k, sl, sr);
        // if the intment is totaly inside the update range
        // ql == qr -> sl == sr
        if(ql <= sl && sr <= qr){
            lazy[k] = v;
            propagate(k, sl, sr);
            return;
        }
        if(ql > sr || sl > qr)
            return;
        
        int mid = (sl + sr)/2;
        update(ql, qr, v, k<<1, sl, mid);
        update(ql, qr, v, k<<1 | 1, mid + 1, sr);
        tree[k] = combine(tree[k<<1], tree[k<<1 | 1]);
    }
};