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
const       int                     mod = 1000000000 + 7;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int  x4[] = {1, 0, -1, 0};
int  y4[] = {0, 1, 0, -1};
int  x8[] = {1,  0, -1, 0, 1, -1, 1, -1};
int  y8[] = { 0, 1, 0, -1, 1, -1, -1, 1};
int  kx[] = {2, -2, 2, -2, 1, -1, 1, -1};
int  ky[] = { -1, 1, 1, -1, 2, -2, -2, 2};


inline bool valid(int x, int y, int rs, int cs, int r, int c) {return ((x >= rs && x <= r) && (y >= cs && y <= c));}

inline int  two(int n) { return 1 << n; }
inline int  db2(int n) {  return n & 1; }
inline bool ispof2 (int x) {return x && (!(x & (x - 1)));}
inline int  check(int n, int b) { return (n >> b) & 1; }
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

class comp { 
    public:
    bool operator()(pii p1,pii p2) 
    { 
        return p1.ss>p2.ss;
    } 
}; 


void dijkstra(int s,int n,vpi *v,vii &lvl)
{
    //cout<<"in 1\n";
    pqueue<pii,vpi,comp>pq;
    int vis[n+10]={0};
    pq.push(mip(s,0LL));
    lvl[s]=0;
    while(!pq.empty())
    {
        //cout<<"    in 2\n";
        pii pr=pq.top();
        int par=pr.ff;
        pq.pop();
        if(vis[pr.ff])continue;
        vis[pr.ff]=1;
        for(auto it:v[par])
        {
            //cout<<"        in 3\n";
            int child=it.ff;
            int child_cost=it.ss;
            if(lvl[child]>lvl[par]+child_cost)
            {
                //cout<<"            in 4\n";
                lvl[child]=lvl[par]+child_cost;
                pq.push(mip(child,lvl[child]));
            }
        }
    }
}

void fileoj()
{
    #ifndef ONLINE_JUDGE
        file_io;
    #endif
}


int32_t main()
{
    /*
    prequ<pii,vpi,comp>pq;
    pq.push(mip(1,2));pq.push(mip(2,1));pq.push(mip(3,2));pq.push(mip(2,4));pq.push(mip(5,1));
    while(!pq.empty())
    {
        wat2(pq.top().ff,pq.top().ss);
        pq.pop();
    }
    return 0;
    */
    
    
    
    //fileoj();
    //fast_io
    int t=1;
    //cin>>t;
    for(int tc=1;tc<=t;tc++)
    {
        int n,e;
        cin>>n>>e;
        vii el;
        vpi v[1000];
        int chk[1000]={0};
        for(int i=0;i<e;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].pb(mip(b,c));
            v[b].pb(mip(a,c));
            if(!chk[a]){el.pb(a);chk[a]=1;}
            if(!chk[b]){el.pb(b);chk[b]=1;}
        }
        n=el.size();

        vii dist(n+10,big);
        dijkstra(el[0],n,&v[0],dist);
        
        for(int i=0;i<11;i++)cout<<i<<" - "<<dist[i]<<nl;
    }
}



































 