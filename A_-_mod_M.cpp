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
#define nl endl

#define f1(i,s,e) for( int i=s;i<e;i++)
#define ff1(i,s,e) for(nt i=s;i>=e;--i)
#define For1(i,n) or( int i=0;i<n+1;++i)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define FO(i,s,e) for(long long int i=1;i*i<=y;i++)
#define rf(i,e,s) for(long long int i=n;i>=0;--i)
#define pass(a)  for(long long int i=n-1;i>=1;i-=2)
#define pb push_back
#define eb emplace_back

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
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n;cin>>n;
int a[n];

sort(a,a+n);
int mini=*min_element(a,a+n);
f1(i,0,n)
{
    cin>>a[i];
    a[i]-=mini;
}
int g = __gcd(a[0],a[1]);
f1(x,2,n)
{
    g=__gcd(g,a[x]);
}

// ll g=__gcd(a[0],a[1]);
// f1(i,2,n)
// g=__gcd(g,a[i]);
// cout<<g<<nl;
int ans=0;
    if(g>1 or g!=0)
    {
        ans=1;
    }
    else
    {
        ans=2;
    }
    cout<<ans<<nl;

return 0;
}