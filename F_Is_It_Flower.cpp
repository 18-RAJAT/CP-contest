#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sza(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
#define print(x) cout<<x<<"\n";
#define PRINT(x,y) cout<<x<<" "<<y<<"\n";
#define G(x) ll x;cin>>x;
#define GG(x,y) ll x,y;cin>>x>>y;
#define GS(s) string s;cin>>s;
#define GSS(s1,s2) string s1,s2;cin>>s1>>s2;
#define GSSS(s1,s2,s3) string s1,s2,s3;cin>>s1>>s2>>s3;
#define GC(c) char c;cin>>c;
#define SUM(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define MINE(a)    (*min_element((a).begin(), (a).end()))
#define MAXE(a)    (*max_element((a).begin(), (a).end()))


const int MAX_N = 2e5 + 5;
const int MAX_NN = 2e5 + 8;
const ll MOD = 1000000007;
const ll INF = 1e18+20;
#define revall(x) x.rbegin(), x.rend()
#define ALL(x) sort(x.rbegin(), x.rend())
#define sortall(x) sort(all(x))
#define reverseall(x) reverse(all(x))



///////////////////////////////////////////////////////////////////////////////////////////////////

#define SCD(t) scanf("%d",&t)
#define SCLD(t) scanf("%ld",&t)
#define SCLLD(t) scanf("%lld",&t)
#define SCC(t) scanf("%c",&t)
#define SCS(t) scanf("%s",t)
#define SCF(t) scanf("%f",&t)
#define SCLF(t) scanf("%lf",&t)
#define MEM(a, b) memset(a, (b), sizeof(a))

#define FOR(i, j, k, in) for (ll i=j ; i<=k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)



///////////////////////////////////////////////////////////////////////////////////////////////////

#define MP make_pair
#define INS insert
#define PB push_back
#define ERS erase
#define LB lower_bound
#define UB upper_bound
#define PF push_front
#define EM emplace
#define EB emplace_back
#define INF (int)1e9
#define EPS 1e-9
// #define MOD 998244353 
#define F first
#define S second
#define PI 3.1415926535897932384626433832795
#define read(type) readInt<type>()
const double pi=acos(-1.0);
#define ll long long
typedef pair<int,int> PII;
typedef vector<long long> VI;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<char> VC;
typedef vector<vector<long long>> VII;
typedef vector<pair<ll,ll>>VPII;
typedef vector<string> VS;
typedef vector<PII> VIII;
typedef vector<VI> VVI;
// typedef vector<string> VS;
typedef map<ll,ll> MPII;
typedef map<char,int> MPCI;
typedef map<string,int> MPSI;
typedef set<long long> seti;
typedef multiset<int> MSETI;
typedef priority_queue<pair<int,int>> PQPII;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
#define nl endl
#define NEW cout<<endl;
 
/* clang-format off */
 
/* TYPES  */
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vd vector<double>
#define mii map<long,long>
#define MPC map<char,int> 
#define miid map<double,long>
#define si set<int>
#define sc set<char>
#define vi vector<int>
#define revs(x,y,z) for(ll i=x;i<=y;i+=z)


//////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/* FUNCTIONS */



#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(i,s,e) for(long long int i=s;i>=e;--i)
#define For1(i,n) (long long int i=0;i<n+1;++i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FO(i,s,e) for(long long int i=1;i*i<=y;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pass(a)  for(long long int i=n-1;i>=1;i-=2)
#define pb push_back
#define ppb pop_back
#define eb emplace_back


//////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





// ----------------------</BITWISE>-------------------------- 
/* a=target variable, b=bit number to act upon 0-n */
#define BIT_SET(a,b) ((a) |= (1ULL<<(b)))
#define BIT_CLEAR(a,b) ((a) &= ~(1ULL<<(b)))
#define BIT_FLIP(a,b) ((a) ^= (1ULL<<(b)))

// '!!' to make sure this returns 0 or 1
#define BIT_CHECK(a,b) (!!((a) & (1ULL<<(b))))

#define BITMASK_SET(x, mask) ((x) |= (mask))
#define BITMASK_CLEAR(x, mask) ((x) &= (~(mask)))
#define BITMASK_FLIP(x, mask) ((x) ^= (mask))
#define BITMASK_CHECK_ALL(x, mask) (!(~(x) & (mask)))
#define BITMASK_CHECK_ANY(x, mask) ((x) & (mask))
#define LSB_ANY(n) (n&(n-1))
#define LSB_CHECK(n) (n&(-n))
// ----------------------</BITWISE END>--------------------------




/****************** Geometry *****************/ 
template <typename T> inline T PointDistanceHorVer(T x1,T y1,T x2, T y2) 
{return abs(x1-x2)+abs(y1-y2);} 
template <typename T> inline T PointDistanceDiagonally(T x1,T y1,T x2, T y2) 
{return sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));} 
template <typename T> inline T PointDistanceMinimum(T x1,T y1,T x2, T y2) 
{ T tmp1=abs(x1-x2); T tmp2=abs(y1-y2); T tmp3=abs(tmp1-tmp2); 
T tmp4=min(tmp1, tmp2); return tmp3+tmp4; } 
template <typename T> inline T PointDistance3D(T x1,T y1,T z1,T x2,T y2,T z2)
{return sqrt(square(x2-x1)+square(y2-y1)+square(z2-z1));} 
 
template <typename T> inline T Cube(T a){return a*a*a;} 
template <typename T> inline T RectengularPrism(T a,T b,T c)
{return a*b*c;}
template <typename T> inline T Pyramid(T base, T height)
{return (1/3)*base*height;}
template <typename T> inline T Ellipsoid(T r1,T r2,T r3) 
{return (4/3)*PI*r1*r2*r3;} 
template <typename T> inline T IrregualarPrism(T base, T height)
{return base*height;} 
template <typename T> inline T Sphere(T radius)
{ return (4/3)*PI*radius*radius*radius;} 
template <typename T> inline T CylinderB(T base, T height)
{return base*height;} // base and height 
template <typename T> inline T CylinderR(T radius, T height)
{return PI*radius*radius*height;} // radius and height 
template <typename T> inline T Cone (T radius,T base, T height)
{return (1/3)*PI*radius*radius*height;} 
/****************** Geometry end *****************/ 


/******* Debugging Class Template *******/


    #define debug(args...)     (Debugger()) , args

    class Debugger
    {
        public:
        Debugger(const std::string& _separator = " - ") :
        first(true), separator(_separator){}

        template<typename ObjectType> Debugger& operator , (const ObjectType& v)
        {
            if(!first)
                std:cerr << separator;
            std::cerr << v;
            first = false;
            return *this;
        }
        ~Debugger() {  std:cerr << endl;}

        private:
        bool first;
        std::string separator;
    };

//////////////////////////////////////////////////////////////////////////////////////////////////////

/* PRINTS */
template <class T>
void print_v(vector<T> &v) { cout << "{"; for (auto x : v) cout << x << ","; cout << "\b}"; }
 
/* UTILS */
ll min(ll a,int b) { if (a<b) return a; return b; }
ll min(int a,ll b) { if (a<b) return a; return b; }
ll max(ll a,int b) { if (a>b) return a; return b; }
ll max(int a,ll b) { if (a>b) return a; return b; }
ll gcd(ll a,ll b) { if (b==0) return a; return gcd(b, a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
string to_upper(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='a'  and  a[i]<='z') a[i]-='a'-'A'; return a; }
string to_lower(string a) { for (int i=0;i<(int)a.size();++i) if (a[i]>='A'  and  a[i]<='Z') a[i]+='a'-'A'; return a; }
 
 
void yes() { cout<<"YES\n"; }
void no() { cout<<"NO\n"; }
bool isSorted(vi &arr){for(int i=0;i<(int)arr.size()-1;i++) if(arr[i] >= arr[i+1]) return false;return true;}
 
 
 
/*  All Required define Pre-Processors and typedef Constants */
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
 
bool isprime(ll n)
{
    ll x=sqrt(n);
    for(int i=2;i<=x;i++)
    {if(n%i==0)return true;}
    return false;
}


//Ho Jayega bhai time lagega aur thodi si mehnat

void solve()
{
    function<int(int,int,vector<vector<int>>&,vector<int>&)>DFS=[&DFS](int node,int parent,vector<vector<int>>&g,vector<int>&vis)->int
    {
        int best=1;
        for(auto& ele:g[node])
        {
            if(vis[ele]==0)
            {
                best=INT_MAX;
            }
            else
            {
                best=max(best,DFS(ele,node,g,vis));
            }
        }
        vis[node]=best+1;
        return vis[node];
    };
    GG(n,m);
    vector<vector<int>>g(n+1);
    cf(i,1,m)
    {
        GG(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int>vis;
    cf(i,1,n)
    {
        if(sza(g[i])==4)
        {
            vis.pb(i);
        }
        // else
        // {
        //     vis.pb(1);
        // }
    }
    int sz=sza(vis);
    if(sz*sz!=n)
    {
        print("NO");
        return;
    }
    bool ok=false;
    vector<int>ndp(n+1,0);
    for(auto& it:vis)
    {
        // if(it.size()==4)
        // {
        //     ok=true;
        //     break;
        // }
        if(DFS(it,it,g,ndp)!=sz)//==n)
        {
            ok=true;
            break;
        }
        // else if(sza(g[it])==4)
        // {
        //     ok=true;
        //     break;
        // }
        // else if(sza(g[it])==3)
        // {
        //     int cnt=0;
        //     for(auto& ele:g[it])
        //     {
        //         if(ndp[ele]==sz)
        //         {
        //             cnt++;
        //         }
        //     }
        //     if(cnt==2)
        //     {
        //         ok=true;
        //         break;
        //     }
        // }
        // else if(sza(g[it])==2)
        // {
        //     int cnt=0;
        //     for(auto& ele:g[it])
        //     {
        //         if(ndp[ele]==sz)
        //         {
        //             cnt++;
        //         }
        //     }
        //     if(cnt==1)
        //     {
        //         ok=true;
        //         break;
        //     }
        // }
        else
        {
            for(auto& ele:g[it])
            {
                if(ndp[ele]==sz)
                {
                    ok=true;
                    break;
                }
            }
        }
        // debug(it,ndp[it]);
    }
    cout<<((ok)?"YES":"NO")<<nl;
}


int main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    std::cout << std::setprecision(15); std::cout << std::fixed;
    ll tc = 1;
    cin >> tc;
    for (ll t = 1; t <= tc; t++) 
    {
        solve();
    }
    return 0;
}