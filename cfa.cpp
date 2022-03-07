#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define     int                     unsigned long long
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
const       int                     mod = 1000000007;
                                          

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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


class node{

public:
 string id;
 string name;
 int arr;
 int dur;
 int ord;
 node(string id,string name,int dur,int arr,int ord)
 {
     this->id = id;
     this->name = name;
     this->arr = arr;
     this->dur = dur;
     this->ord = ord;
 }

};

bool cmp(node n1,node n2)
{
    if(n1.arr==n2.arr)
    {
        if(n1.dur==n2.dur)
        {
            if(n1.ord < n2.ord)
            {
                return true;
            }
            else return false;
        }
        else if(n1.dur<n2.dur)
        {
            return true;
        }
        else return false;
    }
    else if(n1.arr<n2.arr)
    {
        return true;
    }
    return false;
    
}


int32_t main()
{
    file_io;
    int t = 1;
    int k = 0;
    int n;
    vector<vector<node>>vn;
    vector<node>v;
    while(cin>>n)
    {
        
        while(n--)
        {
            int arr,dur,ord;
            string s1,s2;
            cin>>s1>>s2>>dur>>arr>>ord;
            v.pb(node(s1,s2,dur,arr,ord));
        }
        
        sort(v.begin()+k,v.end(),cmp);
        
        int time = 0;
        int turn = 0;
        int strts = v[0].arr;
        
        for(int i=0;i<v.size();i++)
        {
            node nd = v[i];
            int turnA = strts+nd.dur-nd.arr;
            int endA = strts+nd.dur;
            turn+=turnA;
            cout<<i+1<<" "<<nd.id<<" "<<nd.name<<" ("<<strts<<"-"<<endA<<") "<<nd.ord<<" "<<turnA<<nl;
            strts = endA;
        }
        
        cout<<"A.T.T = "<<(float)turn/(int)(v.size())<<nl;
        k=v.size();
        
    }
}
