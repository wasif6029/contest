#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define     int                     long long
#define     unt                     unsigned int
#define     LD                      long double

#define     nl                      "\n"
#define     nspace(s)               for(int i=0;i<s;i++)cout<<" ";
#define     wat1(s,x)               nspace(s) ;  cout << #x << " is " << x << nl;
#define     wat2(s,x,y)             nspace(s) ;  cout << #x << " is " << x << "    " << #y << " is " << y << nl ;
#define     wat3(s,x,y,z)           nspace(s) ;  cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << nl;
#define     wat4(s,x,y,z,a)         nspace(s) ;  cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << nl;
#define     wat5(s,x,y,z,a,b)       nspace(s) ;  cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << "    " << #b << " is " << b << nl;
#define     line                    cout<<"\n";
#define     gap                     cout<<" ";

#define     pii                     pair<int, int>
#define     vpi                     vector<pii>
#define     vii                     vector<int>
#define     vsi                     vector<string>
#define     umap                    unordered_map
#define     pqueue                  priority_queue
#define     mip                     make_pair
#define     pb                      push_back
#define     ppb                     pop_back
#define     pf                      push_front
#define     ppf                     pop_front
#define     ff                      first
#define     ss                      second
#define     all(x)                  x.begin(), x.end()
#define     vlb(x, y)               lower_bound(all(x), y)-x.begin()
#define     vub(x, y)               upper_bound(all(x), y)-x.begin()
#define     printv(x)               cout << #x << " is : " ; for(auto it:x)cout<<it<<"   "; cout<<nl;
#define     takes(a,n,type)         type *a=new type[n+10];
#define     mem(a,x)                memset(a, x, sizeof(a))

#define     sp(x)                   setprecision(x) << fixed
#define     PI                      acos(-1.0)
#define     eps                     1e-12

#define     read                    freopen("input.txt","r",stdin)
#define     write                   freopen("output.txt","w",stdout)
#define     file_io                 read;write
#define     fast_io                 ios_base::sync_with_stdio(0);cin.tie(0)

#define     fbo                     find_by_order
#define     ofk                     order_of_key


inline      int    sci()            {int a;scanf("%lld",&a);return a;}
inline      char   scc()            {char a;scanf("%c",&a);return a;}
inline      double scd()            {double a;scanf("%lf",&a);return a;}

const       int                     big = INT_MAX;
const       int                     sml = INT_MIN;
const       int                     mod = 100000007;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int  x4[] = {1, 0, -1, 0};
int  y4[] = {0, 1, 0, -1};
int  x8[] = {1,  0, -1, 0, 1, -1, 1, -1};
int  y8[] = { 0, 1, 0, -1, 1, -1, -1, 1};
int  kx[] = {2, -2, 2, -2, 1, -1, 1, -1};
int  ky[] = { -1, 1, 1, -1, 2, -2, -2, 2};


inline bool valid(int x, int y, int rs, int cs, int r, int c) {return ((x >= rs && x <= r) && (y >= cs && y <= c));}

inline int  two(int n) { return 1LL << n; }
inline int  db2(int n) {  return !(n & 1LL); }
inline bool ispof2 (int x) {return x && (!(x & (x - 1)));}
inline int  check(int n, int b) { return (n >> b) & 1LL; }
inline void biton(int & n, int b) { n |= two(b); }
inline void bitoff(int & n, int b) { n &= ~two(b); }
inline int  ones(int n) { int res = 0; while (n && ++res) n -= n & (-n); return res; }


int mpow(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0)
    {
        if (y & 1)  res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}


void generate_divisors(vii &ans,vii &v,int x,int mul,map<int,int>&fre)
{
    if(x==v.size())
    {
        ans.pb(mul);
        return ;
    }
    int lim = fre[v[x]];
    for(int i=0;i<=lim;i++)
    {
        generate_divisors(ans,v,x+1,mul,fre);
        mul*=v[x];
    }
}

void divisors(vii &v,int n)
{
    map<int,int>fre;
    vii allfacts,factors;
    //factorize(n,allfacts); 
    bool ok = true;
    for(auto it:allfacts)
    {
        if(!fre[it])factors.pb(it);
        fre[it]++;
    }
    generate_divisors(v,factors,0,1,fre);
    sort(all(v));
}


void fileoj()
{
    #ifndef ONLINE_JUDGE
        file_io;
    #endif
}

class data{
public:
    int even;
    int odd;
};

data trees[2000000];
data lazy[2000000];
int A[2000000];


void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        trees[node].even = !(A[start] & 1);
        trees[node].odd = (A[start] & 1);
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        trees[node].even = trees[2*node].even + trees[2*node+1].even;
        trees[node].odd = trees[2*node].odd + trees[2*node+1].odd;
    }
}


void lazy_p(int start,int end,int node)
{
    if(lazy[node].even != 0)
    { 
        // This node needs to be updated
        trees[node].even += (end - start + 1) * lazy[node].even;    // Update it
        if(start != end)
        {
            lazy[node*2].even += lazy[node].even;                  // Mark child as lazy
            lazy[node*2+1].even += lazy[node].even;                // Mark child as lazy
        }
        lazy[node].even = 0;                                  // Reset it
    }
    if(lazy[node].odd != 0)
    { 
        // This node needs to be updated
        trees[node].odd += (end - start + 1) * lazy[node].odd;    // Update it
        if(start != end)
        {
            lazy[node*2].odd += lazy[node].odd;                  // Mark child as lazy
            lazy[node*2+1].odd += lazy[node].odd;                // Mark child as lazy
        }
        lazy[node].odd = 0;                                  // Reset it
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    lazy_p(start,end,node);
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(val&1)
    {
        if(start >= l and end <= r)
        {
            // Segment is fully within range
            trees[node].odd += (end - start + 1) ;
            if(start != end)
            {
                // Not leaf node
                lazy[node*2].odd += 1;
                lazy[node*2+1].odd += 1;
                lazy[node*2].even -= 1;
                lazy[node*2+1].even -= 1;
            }
            return;
        }
    }
    else
    {
        if(start >= l and end <= r)
        {
            // Segment is fully within range
            trees[node].even += (end - start + 1) ;
            if(start != end)
            {
                // Not leaf node
                lazy[node*2].odd -= 1;
                lazy[node*2+1].odd -= 1;
                lazy[node*2].even += 1;
                lazy[node*2+1].even += 1;
            }
            return;
        }
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    trees[node].even = trees[node*2].even + trees[node*2+1].even;        // Updating root with max value 
    trees[node].odd = trees[node*2].odd + trees[node*2+1].odd;        // Updating root with max value 
}

int queryRange(int c,int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    lazy_p(start,end,node);
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return (c==2)?trees[node].odd:trees[node].even;
    int mid = (start + end) / 2;
    int p1 = queryRange(c,node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(c,node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}


int32_t main()
{
    read;write;
    int t = 1;
    //cin>>t;
    for (int tc = 1; tc <= t; tc++)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            cin>>A[i];
        }
        build(0,1,n);
        int q;
        cin>>q;
        while(q--)
        {
            int c,x,y;
            cin>>c>>x>>y;
            if(c==0)
            {
                updateRange(0,1,n,x,x,y);
            }
            else 
            {
                int ans = queryRange(c,0,1,n,x,y);
                cout<<ans<<nl;
            }
        }

        


        


        
    }
}
