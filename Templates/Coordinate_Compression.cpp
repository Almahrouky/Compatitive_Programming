int n; cin>>n;
int a[n] = {10,30,10,20};
vector<int>v;
for(int i = 0; i < n; ++i) v.emplace_back(a[i]);

sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

for(int i = 0; i < n; ++i)
    a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

for(int i = 0; i < n; ++i)
    cout<<a[i]<<' '<<v[a[i]]<<'\n'; // id origin
