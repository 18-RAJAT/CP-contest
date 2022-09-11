#include<bits/stdc++.h>
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

#define f1(i,s,e) for(long long int i=s;i<e;i++)
#define ff1(i,s,e) for(long long int i=s;i>=e;--i)
#define For1(i,n) or(long long int i=0;i<n+1;++i)
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
typedef vector<long long> VI;

bool helperr(VI a,VI b){
    int n=a.size(),m=b.size();
    int i=0,j=0;
    while(i<n and j<m)
    {
        if(a[i]==b[j])
        {
            i++;j++;
            if(j==m)
            {return true;}
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    return false;
}

void solve(int t)
{
    cout << "Case #" << t << ": ";
    int n,k;cin>>n>>k;
    VI a(n),b(n);
    f1(i,0,n)
    {
        cin>>a[i];
    }
    f1(i,0,n)
    {
        cin>>b[i];
    }
    if(a==b)
    {
        if(k%2==0)cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
        return;
    }
    if(n == 2)
    {
        if(k%2) cout<<"YES"<<nl;
        else cout<<"NO"<<nl;
        return;
    }
    f1(i,0,n)
    {
        a.pb(a[i]);
    }
    if(helperr(a,b) and k>0)cout<<"YES"<<nl;
    else cout<<"NO"<<nl;
}



int main() {
ios_base::sync_with_stdio(0);
cin.tie(0); cout.tie(0);

    ll tc;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve(t);
    }
}   