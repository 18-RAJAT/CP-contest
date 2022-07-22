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
int ttt; cin >> ttt;
while(ttt--) {
//_______________________________________________________//
Rajat_Joshi CSE;
    // Add your solution here
    int n,m;cin>>n>>m;int a[n];
    for(int i=0;i<n;++i)cin>>a[i];
        vector<int>pre(n,0),suf(n,0);
        for(int i=1;i<n;++i){pre[i]=pre[i-1]+max(a[i-1]-a[i],0LL);}
        for(int i=n-2;i>=0;--i){suf[i]=suf[i+1]+max(a[i+1]-a[i],0LL);}

            for(int i=0;i<m;++i)
            {
                int x,y;cin>>x>>y;
                if(x<y)
                    {cout<<pre[y-1]-pre[x-1]<<"\n";}
                else
                    {cout<<suf[y-1]-pre[x-1]<<"\n";}
            }
}
return 0;
}