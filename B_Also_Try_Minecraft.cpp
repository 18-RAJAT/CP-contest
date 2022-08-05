#include<bits/stdc++.h>
#define Rajat_Joshi            main;
#define  CSE             ios_base::sync_with_stdio(false);
#define Joshi           cin.tie(NULL);
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;
#define read(type) readInt<type>()
#define ll long long
#define nL

#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(pass) for(long long int i=n-2;i>=0;--i)
#define For1(i,n) or(long long int i=0;i<n+1;++i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
// #define fo(i,s,e) for(long long int i=1;i*i<=;i++)
#define FO(i,s,e) for(long long int i=1;i*i<=y;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)
#define pb push_back
#define eb emplace_back
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define a first
#define b second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define exp 1e9
#define sz(x) (int((x).size()))
const int MAX_N = 1e5 + 5;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
// int ttt; cin >> ttt;
// while(ttt--) {
//_______________________________________________________//
Rajat_Joshi CSE;
    int a[10001],b[10001],c[10001];
    int n,m;cin>>n>>m;
    cf(i,1,n){cin>>a[i];}
    cf(i,2,n)
    {b[i]=b[i-1]+max(0,a[i-1]-a[i]);}
    rf(i,n,1)
    {c[i]=c[i+1]+max(0,a[i+1]-a[i]);}

    while(m--)
    {
        int x,y;ll ans=0;
        cin>>x>>y;

        if(x<=y){ans+=b[y]-b[x];}
        else{ans+=c[y]-c[x];}
         cout<<ans<<"\n";
    }
// }
return 0;
}