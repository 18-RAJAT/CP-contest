#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define sza(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define revall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))
 
const int MAX_N = 2e5 + 5;
const int MAX_NN = 2e5 + 8;
const ll MOD = 1000000007;
const ll INF = 1e18+20;
#define revall(x) x.rbegin(), x.rend()
#define ALL(x) sort(x.begin(), x.end())
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

#define FOR(i, j, k, in) for (ll i=j ; i<k ; i+=in)
#define RFOR(i, j, k, in) for (ll i=j ; i>=k ; i-=in)
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert( B <= A && A <= C)



///////////////////////////////////////////////////////////////////////////////////////////////////

#define MP make_pair
#define INS insert
#define PB push_back
#define PF push_front
#define INF (int)1e9
#define EPS 1e-9
// #define MOD 998244353 
#define ff first
#define ss second
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





/****************** Prime Generator **********************/ 
// const int N=1e7+10; int prime[20000010]; 
// bool isprime[N]; int nprime; 
// template <typename T> void Sieve(T a) 
// {nprime = 0;memset(isprime,true,sizeof(isprime));
// isprime[1]=false;for(int i=2;i<N;i++){
// if(isprime[i]){prime[nprime++]=i;for(int j=2;i*j<N;j++)
// isprime[i*j]=false;}}}
// template <typename T> inline T PrimeFactors(T n)
// {ll cnt=0,sum=1;for(int i=0; prime[i]*prime[i]<=n 
// and i<nprime;i++){cnt=0;while(n%prime[i]==0)
// {cnt++;n/=prime[i];}sum*=(cnt+1);}
// if(n>1)sum*=2;return sum;} 
/**************** Prime Generator End ********************/




/****************** Fast I/O *****************/
void buff() { ios::sync_with_stdio( false ); cin.tie( nullptr ); }
/****************** Fast I/O *****************/



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
 
 
bool cmp(pair<int,int>x,pair<int,int>y){
    return x.second<y.second;
}
 

//SEGMENT TREE TEMPLATE
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Data {
  // Use required attributes
 
  ll sum;
 
  // Default Values
  Data() : sum(0) {};
};
 
struct SegTree {
  int N;
  vector<Data> seg;
  vector<bool> cLazy;
  vector<ll> lazy;
 
  void init(int n) {
    N = n;
    seg.resize(4 * N + 5);
    cLazy.assign(4 * N + 5, false);
    lazy.assign(4 * N + 5, 0);
  }
 
  // Write reqd merge functions
  void merge(Data &cur, Data &l, Data &r) {
    cur.sum = l.sum + r.sum;
  }
 
  // Handle lazy propagation appriopriately
  void propagate(int node, int L, int R) {
    if (L != R) {
      cLazy[node * 2] = 1;
      cLazy[node * 2 + 1] = 1;
      lazy[node * 2] += lazy[node];
      lazy[node * 2 + 1] += lazy[node];
    }
    seg[node].sum += (R - L + 1) * lazy[node];
    lazy[node] = 0;
    cLazy[node] = 0;
  }
 
  void build(int node, int L, int R) {
    if (L == R) {
      return;
    }
    int M = (L + R) / 2;
    build(node * 2, L, M);
    build(node * 2 + 1, M + 1, R);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
  }
 
  Data Query(int node, int L, int R, int i, int j) {
    if (cLazy[node])
      propagate(node, L, R);
    if (j < L || i > R)
      return Data();
    if (i <= L && R <= j)
      return seg[node];
    int M = (L + R) / 2;
    Data left = Query(node * 2, L, M, i, j);
    Data right = Query(node * 2 + 1, M + 1, R, i, j);
    Data cur;
    merge(cur, left, right);
    return cur;
  }
 
  Data pQuery(int node, int L, int R, int pos) {
    if (cLazy[node])
      propagate(node, L, R);
    if (L == R)
      return seg[node];
    int M = (L + R) / 2;
    if (pos <= M)
      return pQuery(node * 2, L, M, pos);
    else
      return pQuery(node * 2 + 1, M + 1, R, pos);
  }
 
  void Update(int node, int L, int R, int i, int j, int val) {
    if (cLazy[node])
      propagate(node, L, R);
    if (j < L || i > R)
      return;
    if (i <= L && R <= j) {
      cLazy[node] = 1;
      lazy[node] = val;
      propagate(node, L, R);
      return;
    }
    int M = (L + R) / 2;
    Update(node * 2, L, M, i, j, val);
    Update(node * 2 + 1, M + 1, R, i, j, val);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
  }
 
  void pUpdate(int node, int L, int R, int pos, int val) {
    if (cLazy[node])
      propagate(node, L, R);
    if (L == R) {
      cLazy[node] = 1;
      lazy[node] += val;
      propagate(node, L, R);
      return;
    }
    int M = (L + R) / 2;
    if (pos <= M)
      pUpdate(node * 2, L, M, pos, val);
    else
      pUpdate(node * 2 + 1, M + 1, R, pos, val);
    merge(seg[node], seg[node * 2], seg[node * 2 + 1]);
  }
 
  Data query(int pos) { return pQuery(1, 1, N, pos); }
 
  Data query(int l, int r) { return Query(1, 1, N, l, r); }
 
  void update(int pos, int val) { pUpdate(1, 1, N, pos, val); }
 
  void update(int l, int r, int val) { Update(1, 1, N, l, r, val); }
};


////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////

void solve()
{
    int n,m;
    cin>>n>>m;
    vi  p(n+,vi());
    vi c(n+1,vi(n+1));
    vi a(n+1);

    cf(i,1,n)
    {
        cf(j,1,n)
        {
            c[i][j]=INF;
        }
    }
    cf(i,1,n)
    {
        cin>>a[i];
    }
    for(int i=l,u,v;i<=m;++i)
    {
        cin>>u>>v;
        p[u].pb(v);
        p[v].pb(u);
    }
    queue<array<int,3>>Q;
    Q.push({1,n,0});
    while(sze(Q)!=0)
    {
        auto f=Q.front();
        Q.pop();
        if(c[f[0]][f[1]]<=f[2])
        {
            continue;
        }
        c[f[0]][f[1]]=f[2];
        for(auto i:P[f[0]])
        {
            for(auto j:p[f[1]])
            {
                if(a[i]+a[j]==1)
                {
                    Q.push({i,j,f[2]+1});
                }
            }
        }
    }
    cout<<(C[n][1]==INF?-1:C[n][1])<<nl;
}

int main() 
{   
    buff();
    ll tc = 1;
    // cin >> tc;
    for (ll t = 1; t <= tc; t++) 
    {
        solve();
    }
    return 0;
}