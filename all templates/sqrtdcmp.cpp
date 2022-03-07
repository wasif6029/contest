#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define     int                     long long
#define     unt                     unsigned int
#define     LD                      long double

#define     nl                      "\n";
#define     wat1(x)                 cout << #x << " is " << x << nl;
#define     wat2(x,y)               cout << #x << " is " << x << "    " << #y << " is " << y << nl ;
#define     wat3(x,y,z)             cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << nl;
#define     wat4(x,y,z,a)           cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << nl;
#define     wat5(x,y,z,a,b)         cout << #x << " is " << x << "    " << #y << " is " << y << "    "<< #z << " is " << z << "    " << #a << " is " << a << "    " << #b << " is " << b << nl;
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
#define     ff                      first
#define     ss                      second
#define     all(x)                  x.begin(), x.end()
#define     vlb(x, y)               lower_bound(all(x), y)-x.begin()
#define     vub(x, y)               upper_bound(all(x), y)-x.begin()
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

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_bucket_update> pbds;

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



void fileoj()
{
    #ifndef ONLINE_JUDGE
        file_io;
    #endif
}

int calc(int n,int q)
{
    return 10;
}

struct bucket{
  int sum;
  int st;
  int ed;
  int lazy;
};
void propagate(bucket * nd,int x,int *a)
{
    for(int i=nd[x].st;i<=nd[x].ed;i++)
    {
        a[i]+=nd[x].lazy;
    }
    nd[x].lazy=0;
}
int query(int *a,bucket *nd,int st,int ed)
{
    int size=nd[0].ed-nd[0].st;
    int l=st/size,r=ed/size;
    int ans=0;
    if(nd[l].lazy)propagate(nd,l,a);
    for(int i=st;i<=nd[l].ed;i++)
    {
        ans+=a[i];
    }
    for(int i=l+1;i<ed;i++)
    {
        ans+=nd[i].sum;
    }
    if(l==r)return ans;
    if(nd[r].lazy)propagate(nd,r,a);
    for(int i=nd[r].st;i<=ed;i++)
    {
        ans+=a[i];
    }
    return ans;
}
void update(int *a,bucket *nd,int l,int r,int u)
{
    int size=nd[0].ed-nd[0].st;
    int l=st/size,r=ed/size;
    if(nd[l].lazy)propagate(nd,l,a);
    for(int i=st;i<=nd[l].ed;i++)
    {
        a[i]+=u;
        nd[l].sum+=u;
    }
    for(int i=l+1;i<ed;i++)
    {
        nd[i].lazy+=u;
        nd[i].sum+=nd[i].lazy*(nd[i].ed-nd[i].st+1);
    }
    if(l==r)return ;
    if(nd[r].lazy)propagate(nd,r,a);
    for(int i=nd[r].st;i<=ed;i++)
    {
        a[i]+=u;
        nd[r].sum+=u;
    }
}
int init(int *a,bucket *nd,int size,int n)
{
    nd[0].sum=0;
    nd[0].lazy=0;
    for(int i=0;i<n;i++)
    {
        nd[i/size].sum+=a[i];
        if((i+1)%size==0 || i+1==n)
        {
            nd[i/size].st=i;
            nd[(i+1)/size].ed=i+1;
            nd[(i+1)/size].sum=0;
            nd[i+1].lazy=0;
        }
    }
}

void sqrt_dcmp_slv()
{
    int n;
    cin>>n;
    int a[n+10];
    for(int i=0;i<n;i++)cin>>a[i];
    int q;
    cin>>q;
    int size=calc(n,q);
    bucket nd[n+10];
    init(a,nd,size,n);
    
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int u;
            cin>>u;
            update(a,nd,l,r,u);
        }
        else
        {
            int ans=query(a,nd,l,r);
            cout<<ans<<nl;
        }
    }
}



int32_t main()
{
    int T=1;
    cin>>T;
    for(int tc=1;tc<=T;tc++)
    {
        sqrt_dcmp_slv();
    }
}



































 